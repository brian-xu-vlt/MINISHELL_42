==12334== Memcheck, a memory error detector
==12334== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12334== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==12334== Command: ./Minishell
==12334== Parent PID: 18219
==12334== 
--12334-- 
--12334-- Valgrind options:
--12334--    --leak-check=full
--12334--    --show-leak-kinds=all
--12334--    --track-origins=yes
--12334--    --verbose
--12334--    --log-file=valgrind-out.ts
--12334-- Contents of /proc/version:
--12334--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--12334-- 
--12334-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--12334-- Page sizes: currently 4096, max supported 4096
--12334-- Valgrind library directory: /usr/lib/valgrind
--12334-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--12334-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--12334--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--12334--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--12334--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--12334--   .. CRC is valid
--12334-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--12334--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--12334--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--12334--    object doesn't have a symbol table
--12334--    object doesn't have a dynamic symbol table
--12334-- Scheduler: using generic scheduler lock implementation.
--12334-- Reading suppressions file: /usr/lib/valgrind/default.supp
==12334== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-12334-by-user42-on-???
==12334== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-12334-by-user42-on-???
==12334== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-12334-by-user42-on-???
==12334== 
==12334== TO CONTROL THIS PROCESS USING vgdb (which you probably
==12334== don't want to do, unless you know exactly what you're doing,
==12334== or are doing some strange experiment):
==12334==   /usr/lib/valgrind/../../bin/vgdb --pid=12334 ...command...
==12334== 
==12334== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==12334==   /path/to/gdb ./Minishell
==12334== and then give GDB the following command
==12334==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=12334
==12334== --pid is optional if only one valgrind process is running
==12334== 
--12334-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--12334-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--12334-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--12334--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--12334--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--12334--    object doesn't have a symbol table
--12334-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--12334--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--12334--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--12334--    object doesn't have a symbol table
==12334== WARNING: new redirection conflicts with existing -- ignoring it
--12334--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--12334--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--12334-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--12334-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--12334-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--12334--    object doesn't have a symbol table
--12334-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--12334--    object doesn't have a symbol table
--12334-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--12334--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--12334--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--12334--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--12334--   .. CRC is valid
--12334-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--12334--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--12334--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--12334--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--12334--   .. CRC is valid
--12334-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--12334-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--12334-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--12334-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
==12399== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-12399-by-user42-on-???
==12399== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-12399-by-user42-on-???
==12399== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-12399-by-user42-on-???
==12399== 
==12399== TO CONTROL THIS PROCESS USING vgdb (which you probably
==12399== don't want to do, unless you know exactly what you're doing,
==12399== or are doing some strange experiment):
==12399==   /usr/lib/valgrind/../../bin/vgdb --pid=12399 ...command...
==12399== 
==12399== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==12399==   /path/to/gdb ./Minishell
==12399== and then give GDB the following command
==12399==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=12399
==12399== --pid is optional if only one valgrind process is running
==12399== 
--12334-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==12334== 
==12334== HEAP SUMMARY:
==12334==     in use at exit: 98,281 bytes in 231 blocks
==12334==   total heap usage: 417 allocs, 186 frees, 151,597 bytes allocated
==12334== 
==12334== Searching for pointers to 231 not-freed blocks
==12334== Checked 175,832 bytes
==12334== 
==12334== 0 bytes in 1 blocks are still reachable in loss record 1 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x40A572: fill_assign (job_command_fill_bonus.c:44)
==12334==    by 0x40DB14: resize_cmd (job_command_create_utils_bonus.c:17)
==12334==    by 0x40A29F: fill_cmd_model (job_command_create_bonus.c:102)
==12334==    by 0x40D52D: is_end_cmd (job_command_is_something_bonus.c:23)
==12334==    by 0x40D5BF: is_add_cmd (job_command_is_something_bonus.c:38)
==12334==    by 0x4095DA: process_sep (job_command_bonus.c:24)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 0 bytes in 1 blocks are still reachable in loss record 2 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x40A632: fill_exp (job_command_fill_bonus.c:68)
==12334==    by 0x40DB3A: resize_cmd (job_command_create_utils_bonus.c:19)
==12334==    by 0x40A29F: fill_cmd_model (job_command_create_bonus.c:102)
==12334==    by 0x40D52D: is_end_cmd (job_command_is_something_bonus.c:23)
==12334==    by 0x40D5BF: is_add_cmd (job_command_is_something_bonus.c:38)
==12334==    by 0x4095DA: process_sep (job_command_bonus.c:24)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 2 bytes in 1 blocks are still reachable in loss record 3 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x41236C: ft_strdup (ft_strdup.c:21)
==12334==    by 0x406CA1: store_new_env (store_env_bonus.c:11)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071AE: ms_putenv (utils_env_bonus.c:18)
==12334==    by 0x4069EA: set_default_env (init_env_bonus.c:7)
==12334==    by 0x406955: init_env (init_env_bonus.c:52)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 5 bytes in 1 blocks are still reachable in loss record 4 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x41236C: ft_strdup (ft_strdup.c:21)
==12334==    by 0x40EB28: clean_av (clean_redirection_bonus.c:44)
==12334==    by 0x40E9DA: clean_redir_av (clean_redirection_bonus.c:67)
==12334==    by 0x40E831: process_redirection (process_redirection_bonus.c:73)
==12334==    by 0x40DF60: process_clean_command (cleaner_bonus.c:79)
==12334==    by 0x40DEAF: cleaner (cleaner_bonus.c:130)
==12334==    by 0x40E264: process_cleaner (hub_cleaner_bonus.c:7)
==12334==    by 0x40E190: hub_cleaner (hub_cleaner_bonus.c:50)
==12334==    by 0x401884: main (main_bonus.c:91)
==12334== 
==12334== 8 bytes in 1 blocks are still reachable in loss record 5 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x40A43C: fill_name (job_command_fill_bonus.c:16)
==12334==    by 0x40DBD4: fill_data_cmd (job_command_create_utils_bonus.c:34)
==12334==    by 0x40A369: fill_cmd_model (job_command_create_bonus.c:117)
==12334==    by 0x40D501: is_end_cmd (job_command_is_something_bonus.c:20)
==12334==    by 0x40D5BF: is_add_cmd (job_command_is_something_bonus.c:38)
==12334==    by 0x4095DA: process_sep (job_command_bonus.c:24)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 16 bytes in 1 blocks are still reachable in loss record 6 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x411A8D: ft_calloc (ft_calloc.c:22)
==12334==    by 0x4068BF: init_env (init_env_bonus.c:41)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 16 bytes in 1 blocks are still reachable in loss record 7 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412CCA: ft_lstnew (ft_lstnew.c:19)
==12334==    by 0x406D33: store_new_env (store_env_bonus.c:24)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071AE: ms_putenv (utils_env_bonus.c:18)
==12334==    by 0x4069EA: set_default_env (init_env_bonus.c:7)
==12334==    by 0x406955: init_env (init_env_bonus.c:52)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 16 bytes in 1 blocks are still reachable in loss record 8 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412CCA: ft_lstnew (ft_lstnew.c:19)
==12334==    by 0x40A0C6: add_cmd_to_job (job_command_create_bonus.c:52)
==12334==    by 0x40D54F: is_end_cmd (job_command_is_something_bonus.c:25)
==12334==    by 0x40D5BF: is_add_cmd (job_command_is_something_bonus.c:38)
==12334==    by 0x4095DA: process_sep (job_command_bonus.c:24)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 16 bytes in 1 blocks are still reachable in loss record 9 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412CCA: ft_lstnew (ft_lstnew.c:19)
==12334==    by 0x40D303: add_job_to_list (job_init_bonus.c:8)
==12334==    by 0x409659: process_sep (job_command_bonus.c:32)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 16 bytes in 1 blocks are still reachable in loss record 10 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x40EA6C: clean_av (clean_redirection_bonus.c:29)
==12334==    by 0x40E9DA: clean_redir_av (clean_redirection_bonus.c:67)
==12334==    by 0x40E831: process_redirection (process_redirection_bonus.c:73)
==12334==    by 0x40DF60: process_clean_command (cleaner_bonus.c:79)
==12334==    by 0x40DEAF: cleaner (cleaner_bonus.c:130)
==12334==    by 0x40E264: process_cleaner (hub_cleaner_bonus.c:7)
==12334==    by 0x40E190: hub_cleaner (hub_cleaner_bonus.c:50)
==12334==    by 0x401884: main (main_bonus.c:91)
==12334== 
==12334== 24 bytes in 1 blocks are still reachable in loss record 11 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x411A8D: ft_calloc (ft_calloc.c:22)
==12334==    by 0x406C7D: store_new_env (store_env_bonus.c:8)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071AE: ms_putenv (utils_env_bonus.c:18)
==12334==    by 0x4069EA: set_default_env (init_env_bonus.c:7)
==12334==    by 0x406955: init_env (init_env_bonus.c:52)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 24 bytes in 1 blocks are still reachable in loss record 12 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x40D383: init_job (job_init_bonus.c:25)
==12334==    by 0x4094F2: process_sep (job_command_bonus.c:11)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 32 bytes in 1 blocks are still reachable in loss record 13 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FA3: vct_new (vct_new.c:19)
==12334==    by 0x406CD2: store_new_env (store_env_bonus.c:16)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071AE: ms_putenv (utils_env_bonus.c:18)
==12334==    by 0x4069EA: set_default_env (init_env_bonus.c:7)
==12334==    by 0x406955: init_env (init_env_bonus.c:52)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 32 bytes in 1 blocks are still reachable in loss record 14 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FA3: vct_new (vct_new.c:19)
==12334==    by 0x401810: main (main_bonus.c:69)
==12334== 
==12334== 32 bytes in 1 blocks are still reachable in loss record 15 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FA3: vct_new (vct_new.c:19)
==12334==    by 0x404926: init_line_editor (init_line_editor_bonus.c:55)
==12334==    by 0x401834: main (main_bonus.c:72)
==12334== 
==12334== 32 bytes in 1 blocks are still reachable in loss record 16 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FA3: vct_new (vct_new.c:19)
==12334==    by 0x413931: vct_readline (vct_readline.c:41)
==12334==    by 0x4019CD: read_loop (main_bonus.c:10)
==12334==    by 0x401860: main (main_bonus.c:80)
==12334== 
==12334== 144 bytes in 1 blocks are still reachable in loss record 17 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x409F0A: create_cmd (job_command_create_bonus.c:21)
==12334==    by 0x40A080: add_cmd_to_job (job_command_create_bonus.c:45)
==12334==    by 0x40D54F: is_end_cmd (job_command_is_something_bonus.c:25)
==12334==    by 0x40D5BF: is_add_cmd (job_command_is_something_bonus.c:38)
==12334==    by 0x4095DA: process_sep (job_command_bonus.c:24)
==12334==    by 0x409492: get_jobs (job_command_bonus.c:67)
==12334==    by 0x401F54: test_jobs (test_jobs_bonus.c:99)
==12334==    by 0x401A69: process_minishell (main_bonus.c:42)
==12334==    by 0x40186C: main (main_bonus.c:88)
==12334== 
==12334== 216 bytes in 1 blocks are still reachable in loss record 18 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x411A8D: ft_calloc (ft_calloc.c:22)
==12334==    by 0x4048E1: init_line_editor (init_line_editor_bonus.c:50)
==12334==    by 0x401834: main (main_bonus.c:72)
==12334== 
==12334== 434 bytes in 42 blocks are still reachable in loss record 19 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x41236C: ft_strdup (ft_strdup.c:21)
==12334==    by 0x406CA1: store_new_env (store_env_bonus.c:11)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071E1: export_env (utils_env_bonus.c:23)
==12334==    by 0x40693E: init_env (init_env_bonus.c:49)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 656 bytes in 41 blocks are still reachable in loss record 20 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412CCA: ft_lstnew (ft_lstnew.c:19)
==12334==    by 0x406D33: store_new_env (store_env_bonus.c:24)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071E1: export_env (utils_env_bonus.c:23)
==12334==    by 0x40693E: init_env (init_env_bonus.c:49)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 1,008 bytes in 42 blocks are still reachable in loss record 21 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x411A8D: ft_calloc (ft_calloc.c:22)
==12334==    by 0x406C7D: store_new_env (store_env_bonus.c:8)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071E1: export_env (utils_env_bonus.c:23)
==12334==    by 0x40693E: init_env (init_env_bonus.c:49)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 1,344 bytes in 42 blocks are still reachable in loss record 22 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FA3: vct_new (vct_new.c:19)
==12334==    by 0x406CD2: store_new_env (store_env_bonus.c:16)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071E1: export_env (utils_env_bonus.c:23)
==12334==    by 0x40693E: init_env (init_env_bonus.c:49)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 2,048 bytes in 1 blocks are still reachable in loss record 23 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FEA: vct_new (vct_new.c:25)
==12334==    by 0x406CD2: store_new_env (store_env_bonus.c:16)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071AE: ms_putenv (utils_env_bonus.c:18)
==12334==    by 0x4069EA: set_default_env (init_env_bonus.c:7)
==12334==    by 0x406955: init_env (init_env_bonus.c:52)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== 2,048 bytes in 1 blocks are still reachable in loss record 24 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FEA: vct_new (vct_new.c:25)
==12334==    by 0x401810: main (main_bonus.c:69)
==12334== 
==12334== 2,048 bytes in 1 blocks are still reachable in loss record 25 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FEA: vct_new (vct_new.c:25)
==12334==    by 0x404926: init_line_editor (init_line_editor_bonus.c:55)
==12334==    by 0x401834: main (main_bonus.c:72)
==12334== 
==12334== 2,048 bytes in 1 blocks are still reachable in loss record 26 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FEA: vct_new (vct_new.c:25)
==12334==    by 0x413931: vct_readline (vct_readline.c:41)
==12334==    by 0x4019CD: read_loop (main_bonus.c:10)
==12334==    by 0x401860: main (main_bonus.c:80)
==12334== 
==12334== 86,016 bytes in 42 blocks are still reachable in loss record 27 of 27
==12334==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==12334==    by 0x412FEA: vct_new (vct_new.c:25)
==12334==    by 0x406CD2: store_new_env (store_env_bonus.c:16)
==12334==    by 0x406C12: ms_setenv (store_env_bonus.c:51)
==12334==    by 0x406E97: store_env (store_env_bonus.c:79)
==12334==    by 0x4071E1: export_env (utils_env_bonus.c:23)
==12334==    by 0x40693E: init_env (init_env_bonus.c:49)
==12334==    by 0x40180B: main (main_bonus.c:68)
==12334== 
==12334== LEAK SUMMARY:
==12334==    definitely lost: 0 bytes in 0 blocks
==12334==    indirectly lost: 0 bytes in 0 blocks
==12334==      possibly lost: 0 bytes in 0 blocks
==12334==    still reachable: 98,281 bytes in 231 blocks
==12334==         suppressed: 0 bytes in 0 blocks
==12334== 
==12334== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==12334== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
