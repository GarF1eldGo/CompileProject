; ModuleID = 'module'
source_filename = "module"

@_Const_String_ = private constant [14 x i8] c"hello world!\0A\00"
@_Const_String_.1 = private constant [11 x i8] c"%04d %04d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
main:
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @_Const_String_, i32 0, i32 0))
  %printf1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @_Const_String_.1, i32 0, i32 0), i32 2020, i32 601)
  ret i32 0
}
