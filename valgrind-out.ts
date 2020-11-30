==29813== Memcheck, a memory error detector
==29813== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==29813== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==29813== Command: ./Minishell
==29813== Parent PID: 801
==29813== 
--29813-- 
--29813-- Valgrind options:
--29813--    --leak-check=full
--29813--    --show-leak-kinds=all
--29813--    --track-origins=yes
--29813--    --verbose
--29813--    --log-file=valgrind-out.ts
--29813-- Contents of /proc/version:
--29813--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--29813-- 
--29813-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--29813-- Page sizes: currently 4096, max supported 4096
--29813-- Valgrind library directory: /usr/lib/valgrind
--29813-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--29813-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--29813--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--29813--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--29813--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--29813--   .. CRC is valid
--29813-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--29813--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--29813--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--29813--    object doesn't have a symbol table
--29813--    object doesn't have a dynamic symbol table
--29813-- Scheduler: using generic scheduler lock implementation.
--29813-- Reading suppressions file: /usr/lib/valgrind/default.supp
==29813== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-29813-by-???-on-???
==29813== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-29813-by-???-on-???
==29813== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-29813-by-???-on-???
==29813== 
==29813== TO CONTROL THIS PROCESS USING vgdb (which you probably
==29813== don't want to do, unless you know exactly what you're doing,
==29813== or are doing some strange experiment):
==29813==   /usr/lib/valgrind/../../bin/vgdb --pid=29813 ...command...
==29813== 
==29813== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==29813==   /path/to/gdb ./Minishell
==29813== and then give GDB the following command
==29813==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=29813
==29813== --pid is optional if only one valgrind process is running
==29813== 
--29813-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--29813-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--29813-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--29813--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--29813--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--29813--    object doesn't have a symbol table
--29813-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--29813--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--29813--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--29813--    object doesn't have a symbol table
==29813== WARNING: new redirection conflicts with existing -- ignoring it
--29813--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--29813--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--29813-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--29813-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--29813-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--29813--    object doesn't have a symbol table
--29813-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--29813--    object doesn't have a symbol table
--29813-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--29813--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--29813--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--29813--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--29813--   .. CRC is valid
--29813-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--29813--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--29813--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--29813--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--29813--   .. CRC is valid
--29813-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--29813-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--29813-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--29813-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
--29813-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==29813== 
==29813== HEAP SUMMARY:
==29813==     in use at exit: 2,288 bytes in 3 blocks
==29813==   total heap usage: 175 allocs, 172 frees, 115,842 bytes allocated
==29813== 
==29813== Searching for pointers to 3 not-freed blocks
==29813== Checked 77,152 bytes
==29813== 
==29813== 32 bytes in 1 blocks are still reachable in loss record 1 of 3
==29813==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29813==    by 0x4128F3: vct_new (vct_new.c:19)
==29813==    by 0x407AAC: safe_vct_new (general_utils_bonus.c:39)
==29813==    by 0x404354: init_line_editor (init_line_editor_bonus.c:55)
==29813==    by 0x401176: main (main_bonus.c:115)
==29813== 
==29813== 208 bytes in 1 blocks are still reachable in loss record 2 of 3
==29813==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29813==    by 0x4113DD: ft_calloc (ft_calloc.c:22)
==29813==    by 0x404311: init_line_editor (init_line_editor_bonus.c:50)
==29813==    by 0x401176: main (main_bonus.c:115)
==29813== 
==29813== 2,048 bytes in 1 blocks are still reachable in loss record 3 of 3
==29813==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==29813==    by 0x41293A: vct_new (vct_new.c:25)
==29813==    by 0x407AAC: safe_vct_new (general_utils_bonus.c:39)
==29813==    by 0x404354: init_line_editor (init_line_editor_bonus.c:55)
==29813==    by 0x401176: main (main_bonus.c:115)
==29813== 
==29813== LEAK SUMMARY:
==29813==    definitely lost: 0 bytes in 0 blocks
==29813==    indirectly lost: 0 bytes in 0 blocks
==29813==      possibly lost: 0 bytes in 0 blocks
==29813==    still reachable: 2,288 bytes in 3 blocks
==29813==         suppressed: 0 bytes in 0 blocks
==29813== 
==29813== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==29813== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
