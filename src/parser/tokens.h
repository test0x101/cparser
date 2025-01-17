/*
 * This file is part of cparser.
 * Copyright (C) 2012 Matthias Braun <matze@braunis.de>
 */

#define PUNCTUATOR(name, string) T(_ALL, T_##name, string, , false)
#define PUNCTUAVAL(name, string, val) T(_ALL, T_##name, string, = val, false)
#define KEY(mode, x) T(mode, T_##x, #x, , true)
#define ALT(mode, x, val) T(mode, T_##x, #x, = val, true)
/* punctuators */
PUNCTUAVAL(LBRACK, "[", '[')
PUNCTUAVAL(RBRACK, "]", ']')
PUNCTUAVAL(LPAREN, "(", '(')
PUNCTUAVAL(RPAREN, ")", ')')
PUNCTUAVAL(LCURLY, "{", '{')
PUNCTUAVAL(RCURLY, "}", '}')
PUNCTUAVAL(DOT, ".", '.')
PUNCTUAVAL(AND, "&", '&')
ALT(_CXX, bitand, '&')
PUNCTUAVAL(ASTERISK, "*", '*')
PUNCTUAVAL(PLUS, "+", '+')
PUNCTUAVAL(MINUS, "-", '-')
PUNCTUAVAL(TILDE, "~", '~')
ALT(_CXX, compl, '~')
PUNCTUAVAL(EXCLAMATIONMARK, "!", '!')
ALT(_CXX, not, '!')
PUNCTUAVAL(SLASH, "/", '/')
PUNCTUAVAL(PERCENT, "%", '%')
PUNCTUAVAL(LESS, "<", '<')
PUNCTUAVAL(GREATER, ">", '>')
PUNCTUAVAL(CARET, "^", '^')
ALT(_CXX, xor, '^')
PUNCTUAVAL(PIPE, "|", '|')
ALT(_CXX, bitor, '|')
PUNCTUAVAL(QUESTIONMARK, "?", '?')
PUNCTUAVAL(COLON, ":", ':')
PUNCTUAVAL(SEMICOLON, ";", ';')
PUNCTUAVAL(EQUAL, "=", '=')
PUNCTUAVAL(COMMA, ",", ',')
PUNCTUAVAL(HASH, "#", '#')
PUNCTUAVAL(NEWLINE, "newline", '\n')

PUNCTUAVAL(MINUSGREATER, "->", 256)
PUNCTUATOR(PLUSPLUS, "++")
PUNCTUATOR(MINUSMINUS, "--")
PUNCTUATOR(LESSLESS, "<<")
PUNCTUATOR(GREATERGREATER, ">>")
PUNCTUATOR(LESSEQUAL, "<=")
PUNCTUATOR(GREATEREQUAL, ">=")
PUNCTUATOR(EQUALEQUAL, "==")
PUNCTUATOR(EXCLAMATIONMARKEQUAL, "!=")
ALT(_CXX, not_eq, T_EXCLAMATIONMARKEQUAL)
PUNCTUATOR(ANDAND, "&&")
ALT(_CXX, and, T_ANDAND)
PUNCTUATOR(PIPEPIPE, "||")
ALT(_CXX, or, T_PIPEPIPE)
PUNCTUATOR(DOTDOTDOT, "...")
PUNCTUATOR(ASTERISKEQUAL, "*=")
PUNCTUATOR(SLASHEQUAL, "/=")
PUNCTUATOR(PERCENTEQUAL, "%=")
PUNCTUATOR(PLUSEQUAL, "+=")
PUNCTUATOR(MINUSEQUAL, "-=")
PUNCTUATOR(LESSLESSEQUAL, "<<=")
PUNCTUATOR(GREATERGREATEREQUAL, ">>=")
PUNCTUATOR(ANDEQUAL, "&=")
ALT(_CXX, and_eq, T_ANDEQUAL)
PUNCTUATOR(CARETEQUAL, "^=")
ALT(_CXX, xor_eq, T_CARETEQUAL)
PUNCTUATOR(PIPEEQUAL, "|=")
ALT(_CXX, or_eq, T_PIPEEQUAL)
PUNCTUATOR(COLONCOLON, "::")
PUNCTUATOR(HASHHASH, "##")

/* literals, misc */
T(_ALL, T_EOF, "end of input", , false)
T(_ALL, T_IDENTIFIER, "identifier", , false)
T(_ALL, T_NUMBER, "number constant", , false)
T(_ALL, T_CHARACTER_CONSTANT, "character constant", , false)
T(_ALL, T_STRING_LITERAL, "string literal", , false)
T(_ALL, T_MACRO_PARAMETER, "macro parameter", , false)
T(_ALL, T_UNKNOWN_CHAR, "character", , false)

/* keywords */
KEY(_ALL, auto)
KEY(_ALL, break)
KEY(_ALL, case)
KEY(_ALL, char)
KEY(_ALL, const)
ALT(_ALL, __const, T_const)
ALT(_ALL, __const__, T_const)
KEY(_ALL, continue)
KEY(_ALL, default)
KEY(_ALL, do)
KEY(_ALL, double)
KEY(_ALL, else)
KEY(_ALL, enum)
KEY(_ALL, extern)
KEY(_ALL, float)
KEY(_ALL,   for)
KEY(_ALL, goto)
KEY(_ALL, if)
KEY(_ALL, int)
KEY(_ALL, long)
KEY(_ALL, register)
KEY(_ALL, return)
KEY(_ALL, short)
KEY(_ALL, signed)
ALT(_ALL, __signed, T_signed)
ALT(_ALL, __signed__, T_signed)
KEY(_ALL, sizeof)
KEY(_ALL, static)
KEY(_ALL, struct)
KEY(_ALL, switch)
KEY(_ALL, typedef)
KEY(_ALL, union)
KEY(_ALL, unsigned)
KEY(_ALL, void)
KEY(_ALL, volatile)
ALT(_ALL, __volatile, T_volatile)
ALT(_ALL, __volatile__, T_volatile)
KEY(_ALL, while)

/* C99 */
KEY(_C99 | _GNUC, _Bool)
KEY(_C99 | _GNUC, _Complex)
ALT(_ALL, __complex__, T__Complex)
ALT(_ALL, __complex, T__Complex)
KEY(_C99, __func__)
ALT(_ALL, __FUNCTION__, T___func__)
KEY(_C99 | _GNUC, _Imaginary)
KEY(_C99 | _CXX | _GNUC, inline)
ALT(_ALL, __inline, T_inline)
ALT(_ALL, __inline__, T_inline)
KEY(_C99, restrict)
ALT(_ALL, __restrict__, T_restrict)
ALT(_ALL, __restrict, T_restrict)
ALT(_MS, _restrict, T_restrict)

/* C11 */
KEY(_C11, _Alignas)
KEY(_C11, _Alignof)
ALT(_ALL, __alignof__, T__Alignof)
ALT(_ALL, __alignof, T__Alignof)
ALT(_MS, _alignof, T__Alignof)
KEY(_C11, _Atomic)
KEY(_C11, _Generic)
KEY(_C11, _Noreturn)
KEY(_ALL, _Static_assert)
KEY(_C11, _Thread_local)
ALT(_ALL, __thread, T__Thread_local)

/* C++ keywords */
KEY(_CXX, bool)
KEY(_CXX, catch)
KEY(_CXX, class)
KEY(_CXX, const_cast)
KEY(_CXX, delete)
KEY(_CXX, dynamic_cast)
KEY(_CXX, explicit)
KEY(_CXX, export)
KEY(_CXX, false)
KEY(_CXX, friend)
KEY(_CXX, mutable)
KEY(_CXX, namespace)
KEY(_CXX, new)
KEY(_CXX, operator)
KEY(_CXX, private)
KEY(_CXX, protected)
KEY(_CXX, public)
KEY(_CXX, reinterpret_cast)
KEY(_CXX, static_cast)
KEY(_CXX, template)
KEY(_CXX, this)
KEY(_CXX, throw)
KEY(_CXX, true)
KEY(_CXX, try)
KEY(_CXX, typeid)
KEY(_CXX, typename)
KEY(_CXX, using)
KEY(_CXX, virtual)
KEY(_CXX, wchar_t)

/* gcc/ms/cparser extensions */
KEY(_ALL, __extension__)
KEY(_ALL, __builtin_classify_type)
KEY(_ALL, __builtin_va_list)
KEY(_ALL, __builtin_va_arg)
KEY(_ALL, __builtin_va_copy)
KEY(_ALL, __builtin_offsetof)
KEY(_ALL, __builtin_constant_p)
KEY(_ALL, __builtin_types_compatible_p)
KEY(_ALL, __builtin_isgreater)
KEY(_ALL, __builtin_isgreaterequal)
KEY(_ALL, __builtin_isless)
KEY(_ALL, __builtin_islessequal)
KEY(_ALL, __builtin_islessgreater)
KEY(_ALL, __builtin_isunordered)
KEY(_ALL, __PRETTY_FUNCTION__)
KEY(_ALL, __label__)
KEY(_MS, __FUNCSIG__)
KEY(_MS, __FUNCDNAME__)
KEY(_ALL, __real__)
ALT(_ALL, __real, T___real__)
KEY(_ALL, __imag__)
ALT(_ALL, __imag, T___imag__)
KEY(_GNUC | _MS, asm)
ALT(_ALL, __asm__, T_asm)
ALT(_MS, _asm, T_asm)
ALT(_ALL, __asm, T_asm)
KEY(_GNUC, typeof)
ALT(_ALL, __typeof, T_typeof)
ALT(_ALL, __typeof__, T_typeof)
KEY(_ALL, __attribute__)
ALT(_ALL, __attribute, T___attribute__)
KEY(_ALL, __builtin_va_start)
ALT(_ALL, __builtin_stdarg_start, T___builtin_va_start)
KEY(_MS, _near)
ALT(_MS, __near, T__near)
KEY(_MS, _far)
ALT(_MS, __far, T__far)
KEY(_MS, cdecl)
ALT(_MS, _cdecl, T_cdecl)
ALT(_MS, __cdecl, T_cdecl)
KEY(_MS, _stdcall)
ALT(_MS, __stdcall, T__stdcall)
KEY(_MS, _fastcall)
ALT(_MS, __fastcall, T__fastcall)
KEY(_MS, __thiscall)
KEY(_MS, _forceinline)
ALT(_MS, __forceinline, T__forceinline)
KEY(_MS, __unaligned)
KEY(_MS, _assume)
ALT(_MS, __assume, T__assume)
KEY(_MS, _try)
ALT(_MS, __try, T__try)
KEY(_MS, _finally)
ALT(_MS, __finally, T__finally)
KEY(_MS, _leave)
ALT(_MS, __leave, T__leave)
KEY(_MS, _except)
ALT(_MS, __except, T__except)
KEY(_MS, _declspec)
ALT(_MS, __declspec, T__declspec)
KEY(_MS, _based)
ALT(_MS, __based, T__based)
KEY(_MS, __noop)
KEY(_MS, __ptr32)
KEY(_MS, __ptr64)
KEY(_MS, __sptr)
KEY(_MS, __uptr)
KEY(_MS, _w64)
ALT(_MS, __w64, T__w64)
KEY(_MS, _int8)
ALT(_MS, __int8, T__int8)
KEY(_MS, _int16)
ALT(_MS, __int16, T__int16)
KEY(_MS, _int32)
ALT(_MS, __int32, T__int32)
KEY(_MS, _int64)
ALT(_MS, __int64, T__int64)
