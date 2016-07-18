unit lpClassHelper;

{$I includes/lape.inc}

interface

uses
  Classes, SysUtils, lpcompiler, lptypes, lpvartypes;

type
  TLapeCompilerHelper = class helper for TLapeCompiler
  public
    procedure addClass(const Name:string;const Parent:string='TObject');
    procedure addClassVar(const Obj,Item,Typ:string;const Read:Pointer;const Write:Pointer=nil;const Arr:boolean=False;const ArrType:string='UInt32');
  end;

implementation

procedure TLapeCompilerHelper.addClass(const Name:string;const Parent:string='TObject');
begin
   addGlobalType('type '+Parent,Name);
end;

procedure TLapeCompilerHelper.addClassVar(const Obj,Item,Typ:string;const Read:Pointer;const Write:Pointer=nil;const Arr:boolean=False;const ArrType:string='UInt32');
var
   Param:string;

begin
   Param:='';
   if Arr then Param:='const Index:'+ArrType;
   if (Assigned(Read)) then
      addGlobalFunction(obj+'.get'+Item+'('+Param+'):'+Typ,Read);
   if Arr then Param:=Param+'; ';
   if (Assigned(Write)) then
      addGlobalProcedure(Obj+'.set'+Item+'('+Param+'const Value:'+Typ+')',Write);
end;

end.
