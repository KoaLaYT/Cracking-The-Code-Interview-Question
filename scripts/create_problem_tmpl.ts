import * as path from "https://deno.land/std@0.86.0/path/mod.ts";
import { format } from "https://deno.land/std@0.86.0/datetime/mod.ts";

const [baseDir, problemDir, problemName] = Deno.args;

if (!baseDir || !problemDir || !problemName) Deno.exit(1);

const encoder = new TextEncoder();

// 0. prepare problem name
const problemNums = Array.from(
    Deno.readDirSync(path.join(baseDir, problemDir))
).filter(isProblemDir).length;

const newProblemDirName = problemDirName(problemNums);

// 1. update CMakeLists.txt
Deno.writeFileSync(
    path.join(baseDir, problemDir, "CMakeLists.txt"),
    encoder.encode(`\nadd_subdirectory("${newProblemDirName}")`),
    { append: true }
);

// 2. create problem directory
const newProblemDir = path.join(baseDir, problemDir, newProblemDirName);
Deno.mkdirSync(newProblemDir);
Deno.chdir(newProblemDir);

// 3. create template files
const writeCMake = Deno.writeFile(
    "CMakeLists.txt",
    encoder.encode(
        `add_library("${newProblemDirName}" solution.cpp)\n\nadd_executable("${newProblemDirName}_Test" solution_test.cpp)\ntarget_link_libraries("${newProblemDirName}_Test" PRIVATE "${newProblemDirName}" GTest::gtest GTest::gtest_main)`
    )
);

const defineGuard = `${capitalize(problemName)}_${format(
    new Date(),
    "yyyyMMdd"
)}`;
const writeHpp = Deno.writeFile(
    "solution.hpp",
    encoder.encode(`#ifndef ${defineGuard}\n#define ${defineGuard}\n\n#endif`)
);

const writeSolution = Deno.writeFile(
    "solution.cpp",
    encoder.encode(`#include "solution.hpp"`)
);

const writeTest = Deno.writeFile(
    "solution_test.cpp",
    encoder.encode(
        `#include "solution.hpp"\n#include <gtest/gtest.h>\n#include <vector>`
    )
);

await Promise.all([writeCMake, writeHpp, writeSolution, writeTest]);

// =======
// HELPERS
// =======
function isProblemDir(dir: Deno.DirEntry) {
    return dir.isDirectory && Number.isInteger(Number(dir.name.slice(0, 2)));
}

function paddingZero(num: number): string {
    if (num < 10) return "0" + num;
    else return `${num}`;
}

function problemDirName(num: number) {
    // example: 0308-problem-name
    return `${problemDir.slice(0, 2)}${paddingZero(num + 1)}-${problemName}`;
}

function capitalize(name: string) {
    return name
        .split("-")
        .map((part) => part.toUpperCase())
        .join("_");
}
