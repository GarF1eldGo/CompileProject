; ModuleID = 'module'
source_filename = "module"

@_Const_String_ = private constant [6 x i8] c"hello\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @add(i32 %apara, i32 %bpara) {
add:
  %a = alloca i32, align 4
  store i32 %apara, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 %bpara, i32* %b, align 4
  ret i32 0
  %tmpvar = load i32, i32* %a, align 4
  %tmpvar1 = load i32, i32* %b, align 4
  %tmpadd = add i32 %tmpvar, %tmpvar1
  ret i32 %tmpadd
}

define i32 @main() {
main:
  %tmpcall = call i32 @add(i32 1, i32 2)
  %k = alloca i32, align 4
  store i32 %tmpcall, i32* %k, align 4
  br i1 false, label %then, label %else

then:                                             ; preds = %main
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_, i32 0, i32 0))
  br label %merge

else:                                             ; preds = %main
  br label %merge

merge:                                            ; preds = %else, %then
  ret i32 0
}
