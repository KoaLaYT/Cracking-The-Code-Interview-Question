/*
 * @Author: KoaLaYT 
 * @Date: 2021-02-02 22:57:09 
 * @Last Modified by:   KoaLaYT 
 * @Last Modified time: 2021-02-02 22:57:09 
 */

#ifndef ONE_AWAY_20200202
#define ONE_AWAY_20200202

#include <string>

/**
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character. 
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 * 
 * Example:
 *      pale, pal   -> true
 *      pales, pale -> true
 *      pale, bale  -> true
 *      pale, bae   -> false
 */
bool is_one_away(const std::string& s1, const std::string& s2);

#endif