; ModuleID = 'module'
source_filename = "module"

declare i32 @printf(i8*, ...)

declare i32 @scanf(i8*, ...)

define i32 @main() {
main:
  %x = alloca i32, align 4
  store i32 0, i32* %x, align 4
  %y = alloca i32, align 4
  store i32 0, i32* %y, align 4
  %tmpvar = load i32, i32* %x, align 4
  %tmpvar1 = load i32, i32* %y, align 4
  %tmpadd = add i32 %tmpvar, %tmpvar1
  store i32 %tmpadd, i32* %x, align 4
  %tmpvar2 = load i32, i32* %x, align 4
  %tmpvar3 = load i32, i32* %y, align 4
  %tmpadd4 = add i32 %tmpvar2, %tmpvar3
  store i32 %tmpadd4, i32* %x, align 4
  ret i32 0
}
