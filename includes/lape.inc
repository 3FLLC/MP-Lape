{
  Author: Niels A.D
  Project: Lape (http://code.google.com/p/la-pe/)
  License: GNU Lesser GPL (http://www.gnu.org/licenses/lgpl.html)

  Defines for the Lape project.
}

{.$DEFINE Lape_CaseSensitive}            //Case sentive in script
{.$DEFINE Lape_CDECL}                    //CDECL function headers for callbacks/evaluations (useful for plugins/ffi)
{$DEFINE Lape_DoubleKeywordsCache}      //Create a double cache for keywords to speed up parsing (more memory, faster)
{.$DEFINE Lape_EmitPos}                  //Emit source position when compiling (produces known memory leak)
{$DEFINE Lape_Inline}                   //Compile with function inlining where it could be benefitial (faster, harder debugging)
{$DEFINE Lape_PascalLabels}             //Label sections and declarations with colon, instead of label type and label() method
{.$DEFINE Lape_SmallCode}                //Try to keep compiled code as small as possible (packed records, no aligning -- less memory, slower)
{.$DEFINE Lape_Unicode}                  //Use unicodestrings

{..$DEFINE Lape_TrackObjects}             //Track all created classes with a list to check for leaks

{$IFDEF FPC}
  {$MODE objfpc}{$H+}
{$ELSE}
  {$DEFINE Delphi}
  {$POINTERMATH ON}

  {$IFDEF WIN64}
    {$DEFINE CPUX86_64}
  {$ELSE}
    {$DEFINE CPU86}
  {$ENDIF}
{$ENDIF}

{$IF DEFINED(UNICODE) and not DEFINED(Lape_Unicode)}
  {$DEFINE Lape_NeedAnsiStringsUnit}
{$IFEND}
