==790== Memcheck, a memory error detector
==790== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==790== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==790== Command: ./Minishell
==790== Parent PID: 18811
==790== 
--790-- 
--790-- Valgrind options:
--790--    --leak-check=full
--790--    --show-leak-kinds=all
--790--    --track-origins=yes
--790--    --verbose
--790--    --log-file=valgrind-out.ts
--790-- Contents of /proc/version:
--790--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--790-- 
--790-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--790-- Page sizes: currently 4096, max supported 4096
--790-- Valgrind library directory: /usr/lib/valgrind
--790-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--790-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--790--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--790--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--790--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--790--   .. CRC is valid
--790-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--790--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--790--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--790--    object doesn't have a symbol table
--790--    object doesn't have a dynamic symbol table
--790-- Scheduler: using generic scheduler lock implementation.
--790-- Reading suppressions file: /usr/lib/valgrind/default.supp
==790== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-790-by-???-on-???
==790== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-790-by-???-on-???
==790== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-790-by-???-on-???
==790== 
==790== TO CONTROL THIS PROCESS USING vgdb (which you probably
==790== don't want to do, unless you know exactly what you're doing,
==790== or are doing some strange experiment):
==790==   /usr/lib/valgrind/../../bin/vgdb --pid=790 ...command...
==790== 
==790== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==790==   /path/to/gdb ./Minishell
==790== and then give GDB the following command
==790==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=790
==790== --pid is optional if only one valgrind process is running
==790== 
--790-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--790-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--790-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--790--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--790--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--790--    object doesn't have a symbol table
--790-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--790--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--790--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--790--    object doesn't have a symbol table
==790== WARNING: new redirection conflicts with existing -- ignoring it
--790--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--790--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--790-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--790-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--790-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--790--    object doesn't have a symbol table
--790-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--790--    object doesn't have a symbol table
--790-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--790--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--790--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--790--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--790--   .. CRC is valid
--790-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--790--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--790--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--790--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--790--   .. CRC is valid
--790-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--790-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--790-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--790-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
--790-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==790== 
==790== HEAP SUMMARY:
==790==     in use at exit: 25,897 bytes in 64 blocks
==790==   total heap usage: 192 allocs, 128 frees, 81,325 bytes allocated
==790== 
==790== Searching for pointers to 64 not-freed blocks
==790== Checked 100,792 bytes
==790== 
==790== 0 bytes in 1 blocks are still reachable in loss record 1 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x40A562: fill_assign (job_command_fill_bonus.c:44)
==790==    by 0x40DB04: resize_cmd (job_command_create_utils_bonus.c:17)
==790==    by 0x40A28F: fill_cmd_model (job_command_create_bonus.c:102)
==790==    by 0x40D51D: is_end_cmd (job_command_is_something_bonus.c:23)
==790==    by 0x40D5AF: is_add_cmd (job_command_is_something_bonus.c:38)
==790==    by 0x4095CA: process_sep (job_command_bonus.c:24)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 0 bytes in 1 blocks are still reachable in loss record 2 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x40A622: fill_exp (job_command_fill_bonus.c:68)
==790==    by 0x40DB2A: resize_cmd (job_command_create_utils_bonus.c:19)
==790==    by 0x40A28F: fill_cmd_model (job_command_create_bonus.c:102)
==790==    by 0x40D51D: is_end_cmd (job_command_is_something_bonus.c:23)
==790==    by 0x40D5AF: is_add_cmd (job_command_is_something_bonus.c:38)
==790==    by 0x4095CA: process_sep (job_command_bonus.c:24)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 2 bytes in 1 blocks are still reachable in loss record 3 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x4069DA: set_default_env (init_env_bonus.c:7)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 5 bytes in 1 blocks are still reachable in loss record 4 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A0C: set_default_env (init_env_bonus.c:9)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 5 bytes in 1 blocks are still reachable in loss record 5 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A3E: set_default_env (init_env_bonus.c:11)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 5 bytes in 1 blocks are still reachable in loss record 6 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x40EB18: clean_av (clean_redirection_bonus.c:44)
==790==    by 0x40E9CA: clean_redir_av (clean_redirection_bonus.c:67)
==790==    by 0x40E821: process_redirection (process_redirection_bonus.c:73)
==790==    by 0x40DF50: process_clean_command (cleaner_bonus.c:79)
==790==    by 0x40DE9F: cleaner (cleaner_bonus.c:130)
==790==    by 0x40E254: process_cleaner (hub_cleaner_bonus.c:7)
==790==    by 0x40E180: hub_cleaner (hub_cleaner_bonus.c:50)
==790==    by 0x40188C: main (main_bonus.c:92)
==790== 
==790== 6 bytes in 1 blocks are still reachable in loss record 7 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x406A8C: increment_shlevel (init_env_bonus.c:20)
==790==    by 0x40693C: init_env (init_env_bonus.c:54)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 7 bytes in 1 blocks are still reachable in loss record 8 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x4069CA: set_default_env (init_env_bonus.c:6)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 8 bytes in 1 blocks are still reachable in loss record 9 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x40A42C: fill_name (job_command_fill_bonus.c:16)
==790==    by 0x40DBC4: fill_data_cmd (job_command_create_utils_bonus.c:34)
==790==    by 0x40A359: fill_cmd_model (job_command_create_bonus.c:117)
==790==    by 0x40D4F1: is_end_cmd (job_command_is_something_bonus.c:20)
==790==    by 0x40D5AF: is_add_cmd (job_command_is_something_bonus.c:38)
==790==    by 0x4095CA: process_sep (job_command_bonus.c:24)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 10 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x40689D: init_env (init_env_bonus.c:41)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 11 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x4069CA: set_default_env (init_env_bonus.c:6)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 12 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x4069DA: set_default_env (init_env_bonus.c:7)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 13 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A0C: set_default_env (init_env_bonus.c:9)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 14 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A3E: set_default_env (init_env_bonus.c:11)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 15 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x406A8C: increment_shlevel (init_env_bonus.c:20)
==790==    by 0x40693C: init_env (init_env_bonus.c:54)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 16 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x40A0B6: add_cmd_to_job (job_command_create_bonus.c:52)
==790==    by 0x40D53F: is_end_cmd (job_command_is_something_bonus.c:25)
==790==    by 0x40D5AF: is_add_cmd (job_command_is_something_bonus.c:38)
==790==    by 0x4095CA: process_sep (job_command_bonus.c:24)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 17 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x40D2F3: add_job_to_list (job_init_bonus.c:8)
==790==    by 0x409649: process_sep (job_command_bonus.c:32)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 16 bytes in 1 blocks are still reachable in loss record 18 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x40EA5C: clean_av (clean_redirection_bonus.c:29)
==790==    by 0x40E9CA: clean_redir_av (clean_redirection_bonus.c:67)
==790==    by 0x40E821: process_redirection (process_redirection_bonus.c:73)
==790==    by 0x40DF50: process_clean_command (cleaner_bonus.c:79)
==790==    by 0x40DE9F: cleaner (cleaner_bonus.c:130)
==790==    by 0x40E254: process_cleaner (hub_cleaner_bonus.c:7)
==790==    by 0x40E180: hub_cleaner (hub_cleaner_bonus.c:50)
==790==    by 0x40188C: main (main_bonus.c:92)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 19 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x4069CA: set_default_env (init_env_bonus.c:6)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 20 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x4069DA: set_default_env (init_env_bonus.c:7)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 21 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A0C: set_default_env (init_env_bonus.c:9)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 22 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A3E: set_default_env (init_env_bonus.c:11)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 23 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x406A8C: increment_shlevel (init_env_bonus.c:20)
==790==    by 0x40693C: init_env (init_env_bonus.c:54)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 24 bytes in 1 blocks are still reachable in loss record 24 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x40D373: init_job (job_init_bonus.c:25)
==790==    by 0x4094E2: process_sep (job_command_bonus.c:11)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 25 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x4069DA: set_default_env (init_env_bonus.c:7)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 26 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A0C: set_default_env (init_env_bonus.c:9)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 27 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A3E: set_default_env (init_env_bonus.c:11)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 28 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x406A8C: increment_shlevel (init_env_bonus.c:20)
==790==    by 0x40693C: init_env (init_env_bonus.c:54)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 29 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x401818: main (main_bonus.c:70)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 30 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x404936: init_line_editor (init_line_editor_bonus.c:55)
==790==    by 0x40183C: main (main_bonus.c:73)
==790== 
==790== 32 bytes in 1 blocks are still reachable in loss record 31 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x413921: vct_readline (vct_readline.c:41)
==790==    by 0x4019DD: read_loop (main_bonus.c:10)
==790==    by 0x401868: main (main_bonus.c:81)
==790== 
==790== 64 bytes in 4 blocks are still reachable in loss record 32 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412CBA: ft_lstnew (ft_lstnew.c:19)
==790==    by 0x406D23: store_new_env (store_env_bonus.c:24)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x40691C: init_env (init_env_bonus.c:50)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 67 bytes in 5 blocks are still reachable in loss record 33 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x41235C: ft_strdup (ft_strdup.c:21)
==790==    by 0x406C91: store_new_env (store_env_bonus.c:11)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x40691C: init_env (init_env_bonus.c:50)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 120 bytes in 5 blocks are still reachable in loss record 34 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x406C6D: store_new_env (store_env_bonus.c:8)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x40691C: init_env (init_env_bonus.c:50)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 144 bytes in 1 blocks are still reachable in loss record 35 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x409EFA: create_cmd (job_command_create_bonus.c:21)
==790==    by 0x40A070: add_cmd_to_job (job_command_create_bonus.c:45)
==790==    by 0x40D53F: is_end_cmd (job_command_is_something_bonus.c:25)
==790==    by 0x40D5AF: is_add_cmd (job_command_is_something_bonus.c:38)
==790==    by 0x4095CA: process_sep (job_command_bonus.c:24)
==790==    by 0x409482: get_jobs (job_command_bonus.c:67)
==790==    by 0x401F64: test_jobs (test_jobs_bonus.c:99)
==790==    by 0x401A79: process_minishell (main_bonus.c:42)
==790==    by 0x401874: main (main_bonus.c:89)
==790== 
==790== 160 bytes in 5 blocks are still reachable in loss record 36 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412F93: vct_new (vct_new.c:19)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x40691C: init_env (init_env_bonus.c:50)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 216 bytes in 1 blocks are still reachable in loss record 37 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x411A7D: ft_calloc (ft_calloc.c:22)
==790==    by 0x4048F1: init_line_editor (init_line_editor_bonus.c:50)
==790==    by 0x40183C: main (main_bonus.c:73)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 38 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x4069DA: set_default_env (init_env_bonus.c:7)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 39 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A0C: set_default_env (init_env_bonus.c:9)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 40 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x40719E: ms_putenv (utils_env_bonus.c:18)
==790==    by 0x406A3E: set_default_env (init_env_bonus.c:11)
==790==    by 0x406933: init_env (init_env_bonus.c:53)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 41 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x406A8C: increment_shlevel (init_env_bonus.c:20)
==790==    by 0x40693C: init_env (init_env_bonus.c:54)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 42 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x401818: main (main_bonus.c:70)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 43 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x404936: init_line_editor (init_line_editor_bonus.c:55)
==790==    by 0x40183C: main (main_bonus.c:73)
==790== 
==790== 2,048 bytes in 1 blocks are still reachable in loss record 44 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x413921: vct_readline (vct_readline.c:41)
==790==    by 0x4019DD: read_loop (main_bonus.c:10)
==790==    by 0x401868: main (main_bonus.c:81)
==790== 
==790== 10,240 bytes in 5 blocks are still reachable in loss record 45 of 45
==790==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==790==    by 0x412FDA: vct_new (vct_new.c:25)
==790==    by 0x406CC2: store_new_env (store_env_bonus.c:16)
==790==    by 0x406C02: ms_setenv (store_env_bonus.c:51)
==790==    by 0x406E87: store_env (store_env_bonus.c:79)
==790==    by 0x4071D1: export_env (utils_env_bonus.c:23)
==790==    by 0x40691C: init_env (init_env_bonus.c:50)
==790==    by 0x40180B: main (main_bonus.c:68)
==790== 
==790== LEAK SUMMARY:
==790==    definitely lost: 0 bytes in 0 blocks
==790==    indirectly lost: 0 bytes in 0 blocks
==790==      possibly lost: 0 bytes in 0 blocks
==790==    still reachable: 25,897 bytes in 64 blocks
==790==         suppressed: 0 bytes in 0 blocks
==790== 
==790== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==790== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
