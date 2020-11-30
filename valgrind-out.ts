==1602== Memcheck, a memory error detector
==1602== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1602== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1602== Command: ./Minishell
==1602== Parent PID: 28915
==1602== 
--1602-- 
--1602-- Valgrind options:
--1602--    --leak-check=full
--1602--    --show-leak-kinds=all
--1602--    --track-origins=yes
--1602--    --verbose
--1602--    --log-file=valgrind-out.ts
--1602-- Contents of /proc/version:
--1602--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--1602-- 
--1602-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--1602-- Page sizes: currently 4096, max supported 4096
--1602-- Valgrind library directory: /usr/lib/valgrind
--1602-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--1602-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--1602--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--1602--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--1602--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--1602--   .. CRC is valid
--1602-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--1602--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--1602--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--1602--    object doesn't have a symbol table
--1602--    object doesn't have a dynamic symbol table
--1602-- Scheduler: using generic scheduler lock implementation.
--1602-- Reading suppressions file: /usr/lib/valgrind/default.supp
==1602== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-1602-by-user42-on-???
==1602== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-1602-by-user42-on-???
==1602== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-1602-by-user42-on-???
==1602== 
==1602== TO CONTROL THIS PROCESS USING vgdb (which you probably
==1602== don't want to do, unless you know exactly what you're doing,
==1602== or are doing some strange experiment):
==1602==   /usr/lib/valgrind/../../bin/vgdb --pid=1602 ...command...
==1602== 
==1602== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==1602==   /path/to/gdb ./Minishell
==1602== and then give GDB the following command
==1602==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=1602
==1602== --pid is optional if only one valgrind process is running
==1602== 
--1602-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--1602-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--1602-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--1602--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--1602--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--1602--    object doesn't have a symbol table
--1602-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--1602--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--1602--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--1602--    object doesn't have a symbol table
==1602== WARNING: new redirection conflicts with existing -- ignoring it
--1602--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--1602--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--1602-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--1602-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--1602-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--1602--    object doesn't have a symbol table
--1602-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--1602--    object doesn't have a symbol table
--1602-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--1602--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--1602--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--1602--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--1602--   .. CRC is valid
--1602-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--1602--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--1602--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--1602--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--1602--   .. CRC is valid
--1602-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--1602-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--1602-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--1602-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
==1636== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-1636-by-user42-on-???
==1636== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-1636-by-user42-on-???
==1636== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-1636-by-user42-on-???
==1636== 
==1636== TO CONTROL THIS PROCESS USING vgdb (which you probably
==1636== don't want to do, unless you know exactly what you're doing,
==1636== or are doing some strange experiment):
==1636==   /usr/lib/valgrind/../../bin/vgdb --pid=1636 ...command...
==1636== 
==1636== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==1636==   /path/to/gdb ./Minishell
==1636== and then give GDB the following command
==1636==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=1636
==1636== --pid is optional if only one valgrind process is running
==1636== 
--1602-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==1602== 
==1602== HEAP SUMMARY:
==1602==     in use at exit: 0 bytes in 0 blocks
==1602==   total heap usage: 1,032 allocs, 1,032 frees, 701,263 bytes allocated
==1602== 
==1602== All heap blocks were freed -- no leaks are possible
==1602== 
==1602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==1602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
