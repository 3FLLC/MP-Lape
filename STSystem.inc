{$mode objfpc}
{$IFDEF FPC}
function LoOf8bit(const B: Byte): Byte;
begin
   Result := B and $0F;
end;

function LoOf16bit(const Si: Word): Byte;
begin
{$IFDEF ASSEMBLY}
   asm
      MOV AX, &Si;
      MOV Result, AL;
   end;
{$ELSE}
   Result := Byte(Si and $FF);
{$ENDIF}
end;

function LoOf32bit(const Li: Cardinal): Word;
begin
{$IFDEF ASSEMBLY}
   asm
      MOV EAX, Li;
      MOV Result, AX;
   end;
{$ELSE}
   Result := Li and $FFFF;
{$ENDIF}
end;
{$ENDIF}

procedure SelfTestSystemUnit;
Var
   B:Byte;
   W:Word;
   L:Longint;
   LW:Longword;

Begin
   B:=10;
   Assert(Lo(B)=10,'Lo');
   B:=255;
   Assert(Lo(B)=15,'Lo Nibble');
   Assert(LoOf8bit(B)=15,'Math LoOf8bit');
   W:=10;
   Assert(Lo(W)=10,'Lo Word');
   W:=65535;
   Assert(Lo(W)=255,'Lo Byte');
   Assert(LoOf16bit(W)=255,'Math LoOf16bit');
   L:=10;
   Assert(Lo(L)=10,'Lo 32bit');
   L:=$FFFFFFFF;
   Assert(Lo(L)=65535,'Lo Word');
   Assert(LoOf32bit(L)=65535,'Math LoOf32bit');
   LW:=10;
   Assert(Lo(LW)=10,'Lo Word');
   LW:=$FFFFFFFF;
   Assert(Lo(LW)=65535,'Lo Word');
   Assert(LoOf32bit(LW)=65535,'Lo Word');
   L:=-1;
   Assert(Lo(L)=65535,'Lo Word');
   Assert(LoOf32bit(L)=65535,'Math LoOf32bit');
End;

{$IFDEF FPC}
begin
   SelfTestSystemUnit;
end;
{$ENDIF}
