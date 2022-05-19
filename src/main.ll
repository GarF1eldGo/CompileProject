; ModuleID = 'module'
source_filename = "module"

declare i32 @printf(i8* %0, ...)

declare i32 @scanf(i8* %0, ...)

define i32 @main() {
main:
  %x = alloca [0 x [4 x i32]], align 4
  ret void
}
