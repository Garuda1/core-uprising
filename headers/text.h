/*
 * text.h
 *
 */

#ifndef TEXT_H
#define TEXT_H

#define COLOUR_RESET "\x1B[0m"
#define COLOUR_RED   "\x1B[31m"
#define TEXT_FAILURE "[" COLOUR_RED "FAILURE" COLOUR_RESET "] "

#define TEXT_ARGS_INVALIDARG    TEXT_FAILURE "args_parse: invalid argument (%s)"
#define TEXT_ARGS_PARSE_FAILURE TEXT_FAILURE "args_parse: failed to parse argument"

#define TEXT_MAIN_FAILURE       TEXT_FAILURE "core-uprising failed to execute properly"

#endif
