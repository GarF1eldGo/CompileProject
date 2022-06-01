; ModuleID = 'run/main-optimized-branch.bc'
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
}

define i32 @main() {
main:
  %tmpcall = call i32 @add(i32 1, i32 2)
  %k = alloca i32, align 4
  store i32 %tmpcall, i32* %k, align 4
  br label %else

else:                                             ; preds = %main
  br label %merge

merge:                                            ; preds = %else
  ret i32 0
}
