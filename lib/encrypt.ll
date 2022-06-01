; ModuleID = 'encrypt.c'
source_filename = "encrypt.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@decrypted = dso_local global [10007 x i32] zeroinitializer, align 16

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @hash(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = srem i32 %3, 10007
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @__encrypt(i8* %0) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  store i8* %0, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = ptrtoint i8* %4 to i32
  %6 = call i32 @hash(i32 %5)
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [10007 x i32], [10007 x i32]* @decrypted, i64 0, i64 %7
  store i32 0, i32* %8, align 4
  %9 = load i8*, i8** %2, align 8
  store i8* %9, i8** %3, align 8
  br label %10

10:                                               ; preds = %14, %1
  %11 = load i8*, i8** %3, align 8
  %12 = load i8, i8* %11, align 1
  %13 = icmp ne i8 %12, 0
  br i1 %13, label %14, label %22

14:                                               ; preds = %10
  %15 = load i8*, i8** %3, align 8
  %16 = load i8, i8* %15, align 1
  %17 = sext i8 %16 to i32
  %18 = xor i32 %17, 42
  %19 = trunc i32 %18 to i8
  store i8 %19, i8* %15, align 1
  %20 = load i8*, i8** %3, align 8
  %21 = getelementptr inbounds i8, i8* %20, i32 1
  store i8* %21, i8** %3, align 8
  br label %10, !llvm.loop !4

22:                                               ; preds = %10
  %23 = load i8*, i8** %2, align 8
  ret i8* %23
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @__decrypt(i8* %0) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i8*, align 8
  store i8* %0, i8** %3, align 8
  %5 = load i8*, i8** %3, align 8
  %6 = ptrtoint i8* %5 to i32
  %7 = call i32 @hash(i32 %6)
  %8 = sext i32 %7 to i64
  %9 = getelementptr inbounds [10007 x i32], [10007 x i32]* @decrypted, i64 0, i64 %8
  %10 = load i32, i32* %9, align 4
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %33, label %12

12:                                               ; preds = %1
  %13 = load i8*, i8** %3, align 8
  store i8* %13, i8** %4, align 8
  br label %14

14:                                               ; preds = %18, %12
  %15 = load i8*, i8** %4, align 8
  %16 = load i8, i8* %15, align 1
  %17 = icmp ne i8 %16, 0
  br i1 %17, label %18, label %26

18:                                               ; preds = %14
  %19 = load i8*, i8** %4, align 8
  %20 = load i8, i8* %19, align 1
  %21 = sext i8 %20 to i32
  %22 = xor i32 %21, 42
  %23 = trunc i32 %22 to i8
  store i8 %23, i8* %19, align 1
  %24 = load i8*, i8** %4, align 8
  %25 = getelementptr inbounds i8, i8* %24, i32 1
  store i8* %25, i8** %4, align 8
  br label %14, !llvm.loop !6

26:                                               ; preds = %14
  %27 = load i8*, i8** %3, align 8
  %28 = ptrtoint i8* %27 to i32
  %29 = call i32 @hash(i32 %28)
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds [10007 x i32], [10007 x i32]* @decrypted, i64 0, i64 %30
  store i32 1, i32* %31, align 4
  %32 = load i8*, i8** %3, align 8
  store i8* %32, i8** %2, align 8
  br label %35

33:                                               ; preds = %1
  %34 = load i8*, i8** %3, align 8
  store i8* %34, i8** %2, align 8
  br label %35

35:                                               ; preds = %33, %26
  %36 = load i8*, i8** %2, align 8
  ret i8* %36
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"uwtable", i32 1}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{!"Ubuntu clang version 13.0.1-++20220120110955+75e33f71c2da-1~exp1~20220120231006.63"}
!4 = distinct !{!4, !5}
!5 = !{!"llvm.loop.mustprogress"}
!6 = distinct !{!6, !5}
