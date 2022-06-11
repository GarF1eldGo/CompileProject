; ModuleID = 'run/main-obfuscate.bc'
source_filename = "module"

@_Const_String_ = private global [4 x i8] c"\0FN \00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @func(i32 %xpara, i32 %ypara) {
func:
  %x = alloca i32, align 4
  store i32 %xpara, i32* %x, align 4
  %y = alloca i32, align 4
  store i32 %ypara, i32* %y, align 4
  ret i32 0

0:                                                ; No predecessors!
  %tmpvar = load i32, i32* %x, align 4
  %tmpvar1 = load i32, i32* %y, align 4
  %tmpadd = add i32 %tmpvar, %tmpvar1
  ret i32 %tmpadd
}

define i32 @main() {
main:
  %tmpcall = call i32 @func(i32 1, i32 1)
  %a = alloca i32, align 4
  store i32 %tmpcall, i32* %a, align 4
  %tmpvar = load i32, i32* %a, align 4
  %0 = call i8* @__decrypt(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_, i32 0, i32 0))
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_, i32 0, i32 0), i32 %tmpvar)
  %1 = call i8* @__encrypt(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_, i32 0, i32 0))
  ret i32 0
}

declare i8* @__decrypt(i8*)

declare i8* @__encrypt(i8*)
