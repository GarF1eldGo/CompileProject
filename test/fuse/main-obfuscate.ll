; ModuleID = 'fuse/main-obfuscate.bc'
source_filename = "module"

@_Const_String_ = private global [14 x i8] c"BOFFE\0A]EXFN\0B \00"
@_Const_String_.1 = private global [11 x i8] c"\0F\1A\1EN\0A\0F\1A\1EN \00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
main:
  %0 = call i8* @__decrypt(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_Const_String_, i32 0, i32 0))
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_Const_String_, i32 0, i32 0))
  %1 = call i8* @__encrypt(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_Const_String_, i32 0, i32 0))
  %2 = call i8* @__decrypt(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @_Const_String_.1, i32 0, i32 0))
  %printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @_Const_String_.1, i32 0, i32 0), i32 2020, i32 601)
  %3 = call i8* @__encrypt(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @_Const_String_.1, i32 0, i32 0))
  ret i32 0
}

declare i8* @__decrypt(i8*)

declare i8* @__encrypt(i8*)
