; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.43.34809"

$"??_C@_05CJBACGMB@hello?$AA@" = comdat any

$"??_C@_02LOEMLMCB@my?$AA@" = comdat any

$"??_C@_04MEMAJGDJ@name?$AA@" = comdat any

$"??_C@_02EDKKPMHH@is?$AA@" = comdat any

$"??_C@_07BFIHACOC@Michael?$AA@" = comdat any

@"??_C@_05CJBACGMB@hello?$AA@" = linkonce_odr dso_local unnamed_addr constant [6 x i8] c"hello\00", comdat, align 1
@one = dso_local global ptr @"??_C@_05CJBACGMB@hello?$AA@", align 8
@"??_C@_02LOEMLMCB@my?$AA@" = linkonce_odr dso_local unnamed_addr constant [3 x i8] c"my\00", comdat, align 1
@two = dso_local global ptr @"??_C@_02LOEMLMCB@my?$AA@", align 8
@"??_C@_04MEMAJGDJ@name?$AA@" = linkonce_odr dso_local unnamed_addr constant [5 x i8] c"name\00", comdat, align 1
@three = dso_local global ptr @"??_C@_04MEMAJGDJ@name?$AA@", align 8
@"??_C@_02EDKKPMHH@is?$AA@" = linkonce_odr dso_local unnamed_addr constant [3 x i8] c"is\00", comdat, align 1
@four = dso_local global ptr @"??_C@_02EDKKPMHH@is?$AA@", align 8
@"??_C@_07BFIHACOC@Michael?$AA@" = linkonce_odr dso_local unnamed_addr constant [8 x i8] c"Michael\00", comdat, align 1
@five = dso_local global ptr @"??_C@_07BFIHACOC@Michael?$AA@", align 8

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  store i32 0, ptr %retval, align 4
  ret i32 0
}

attributes #0 = { noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"clang version 21.0.0git (https://github.com/llvm/llvm-project.git 316f68f7f250b0a5de1d7cbe06a97a5901af6057)"}
