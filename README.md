Modern Pascal
=============

[![Build Status](https://travis-ci.org/nielsAD/lape.svg?branch=master)](https://travis-ci.org/nielsAD/lape)

Modern Pascal is a compiler and script engine based upon a Lape variance. Lape itself is a scripting engine with a Pascal derived syntax for Free Pascal and Delphi. Modern Pascal syntax is backwards compatible with Turbo Pascal and Object Pascal, with a few variances. The parser has also been expanded to optionally support modern grammar from C# and JavaScript languages, along with some personal wishes.

Modern Pascal is:
- A scripting engine
    - Code can be interpreted while in p-code (portable code .obj) state
- A cross-platform compiler
    - See Portable below.
- A Pascal derived language
    - Basetypes: `Boolean`, `Byte`, `SmallInt`, `Word`, `Integer`, `Longint`, `LongWord`, `LargeInt`, `LargeWord`, `Single`, `Double`, `Extended`, `Currency`, `Char`, `String`, `AnsiChar`, `AnsiString`, `WideChar`, `WideString`, `Variant`, `Array`, `Record`, `Union`, `Class`, `Enum`, `Set`, `Pointer`, `Function pointer`
    - Operations: `:=` `=` `==` `<>` `!=` `>` `>=` `<` `<=` `@` `^` `+` `-` `*` `/` `**` `AND` `OR` `DIV` `XOR` `NOT` `MOD` `&&` `||` `IN` `SHL` `SHR`
    - Constructs: `If`, `Case`, `For`, `Repeat`, `While`, `Try`, `Except`, `Finally`, `Label`
    - Comments: `//`, `/* */`, `(* *)`, `{ }`
    - String Delimeters: `''`, `""`
    - Numeric Notations: `0`, `1`, `2`, `3`, `4`, `5`, `6`, `7`, `8`, `9`, `#01`, `0x01`, `$01`, `0xb01`, `0xo111`, `0111`
    - Internal and external (overloaded) functions (with support for default params)
    - Internal/external variables and constants (every variable is represented exactly as how it would be by FPC/Delphi)
    - Support for local (nested) declarations. So function can have their own constants/types/variables/functions.
    - Units, internal RTL and external via Dynamically Linked Libraries across each Operating System
- Portable
    - Fully written in FPC. No need for external libraries.
    - Tested with Linux(x86/x64), Windows(x86/x64), Mac OS, and Raspberry Pi, but supports virtually every platform FPC supports.
- Extensible
    - New types can easily be added with specified behaviour for operations.
    - Optional foreign function interface which allows native calling of Lape functions and importing of functions without creating wrappers.
- Fast
    - Hard coded parser for performance
    - Native variable address instead of object or variant wrappers
    - Extremely right AST loop for execution
