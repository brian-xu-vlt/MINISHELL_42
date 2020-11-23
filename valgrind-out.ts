==5605== Memcheck, a memory error detector
==5605== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5605== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5605== Command: ./Minishell
==5605== Parent PID: 16820
==5605== 
--5605-- 
--5605-- Valgrind options:
--5605--    --leak-check=full
--5605--    --show-leak-kinds=all
--5605--    --track-origins=yes
--5605--    --verbose
--5605--    --log-file=valgrind-out.ts
--5605-- Contents of /proc/version:
--5605--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--5605-- 
--5605-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--5605-- Page sizes: currently 4096, max supported 4096
--5605-- Valgrind library directory: /usr/lib/valgrind
--5605-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--5605-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--5605--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--5605--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--5605--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--5605--   .. CRC is valid
--5605-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--5605--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--5605--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--5605--    object doesn't have a symbol table
--5605--    object doesn't have a dynamic symbol table
--5605-- Scheduler: using generic scheduler lock implementation.
--5605-- Reading suppressions file: /usr/lib/valgrind/default.supp
==5605== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-5605-by-user42-on-???
==5605== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-5605-by-user42-on-???
==5605== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-5605-by-user42-on-???
==5605== 
==5605== TO CONTROL THIS PROCESS USING vgdb (which you probably
==5605== don't want to do, unless you know exactly what you're doing,
==5605== or are doing some strange experiment):
==5605==   /usr/lib/valgrind/../../bin/vgdb --pid=5605 ...command...
==5605== 
==5605== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==5605==   /path/to/gdb ./Minishell
==5605== and then give GDB the following command
==5605==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=5605
==5605== --pid is optional if only one valgrind process is running
==5605== 
--5605-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--5605-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--5605-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--5605--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--5605--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--5605--    object doesn't have a symbol table
--5605-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--5605--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--5605--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--5605--    object doesn't have a symbol table
==5605== WARNING: new redirection conflicts with existing -- ignoring it
--5605--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--5605--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--5605-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--5605-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--5605-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--5605--    object doesn't have a symbol table
--5605-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--5605--    object doesn't have a symbol table
--5605-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--5605--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--5605--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--5605--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--5605--   .. CRC is valid
--5605-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--5605--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--5605--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--5605--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--5605--   .. CRC is valid
--5605-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--5605-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--5605-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--5605-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
==5674== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-5674-by-user42-on-???
==5674== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-5674-by-user42-on-???
==5674== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-5674-by-user42-on-???
==5674== 
==5674== TO CONTROL THIS PROCESS USING vgdb (which you probably
==5674== don't want to do, unless you know exactly what you're doing,
==5674== or are doing some strange experiment):
==5674==   /usr/lib/valgrind/../../bin/vgdb --pid=5674 ...command...
==5674== 
==5674== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==5674==   /path/to/gdb ./Minishell
==5674== and then give GDB the following command
==5674==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=5674
==5674== --pid is optional if only one valgrind process is running
==5674== 
==5690== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-5690-by-user42-on-???
==5690== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-5690-by-user42-on-???
==5690== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-5690-by-user42-on-???
==5690== 
==5690== TO CONTROL THIS PROCESS USING vgdb (which you probably
==5690== don't want to do, unless you know exactly what you're doing,
==5690== or are doing some strange experiment):
==5690==   /usr/lib/valgrind/../../bin/vgdb --pid=5690 ...command...
==5690== 
==5690== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==5690==   /path/to/gdb ./Minishell
==5690== and then give GDB the following command
==5690==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=5690
==5690== --pid is optional if only one valgrind process is running
==5690== 
--5605-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==5605== 
==5605== HEAP SUMMARY:
==5605==     in use at exit: 2,525 bytes in 12 blocks
==5605==   total heap usage: 468 allocs, 456 frees, 174,970 bytes allocated
==5605== 
==5605== Searching for pointers to 12 not-freed blocks
==5605== Checked 80,392 bytes
==5605== 
==5605== 0 bytes in 1 blocks are still reachable in loss record 1 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40A502: fill_assign (job_command_fill_bonus.c:38)
==5605==    by 0x40B1D4: resize_cmd (job_command_create_utils_bonus.c:17)
==5605==    by 0x40A24F: fill_cmd_model (job_command_create_bonus.c:96)
==5605==    by 0x40ABED: is_end_cmd (job_command_is_something_bonus.c:23)
==5605==    by 0x40AC7F: is_add_cmd (job_command_is_something_bonus.c:38)
==5605==    by 0x409745: process_sep (job_command_bonus.c:28)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 0 bytes in 1 blocks are still reachable in loss record 2 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40A5B2: fill_exp (job_command_fill_bonus.c:59)
==5605==    by 0x40B1FA: resize_cmd (job_command_create_utils_bonus.c:19)
==5605==    by 0x40A24F: fill_cmd_model (job_command_create_bonus.c:96)
==5605==    by 0x40ABED: is_end_cmd (job_command_is_something_bonus.c:23)
==5605==    by 0x40AC7F: is_add_cmd (job_command_is_something_bonus.c:38)
==5605==    by 0x409745: process_sep (job_command_bonus.c:28)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 5 bytes in 1 blocks are still reachable in loss record 3 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40FE1C: ft_strdup (ft_strdup.c:21)
==5605==    by 0x40BD60: clean_av (clean_redirection_bonus.c:59)
==5605==    by 0x40BC4A: clean_redir_av (clean_redirection_bonus.c:82)
==5605==    by 0x40BB9E: hub_process_redirection (process_redirection_bonus.c:7)
==5605==    by 0x40BA2F: process_redirection (process_redirection_bonus.c:21)
==5605==    by 0x40B5C9: is_redirection (cleaner_bonus.c:7)
==5605==    by 0x40B529: process_clean_command (cleaner_bonus.c:35)
==5605==    by 0x40B47F: cleaner (cleaner_bonus.c:82)
==5605==    by 0x40B754: process_cleaner (hub_cleaner_bonus.c:7)
==5605==    by 0x40B680: hub_cleaner (hub_cleaner_bonus.c:49)
==5605==    by 0x40180C: main (main_bonus.c:92)
==5605== 
==5605== 8 bytes in 1 blocks are still reachable in loss record 4 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40A3D9: fill_name (job_command_fill_bonus.c:13)
==5605==    by 0x40B294: fill_data_cmd (job_command_create_utils_bonus.c:34)
==5605==    by 0x40A319: fill_cmd_model (job_command_create_bonus.c:111)
==5605==    by 0x40ABC1: is_end_cmd (job_command_is_something_bonus.c:20)
==5605==    by 0x40AC7F: is_add_cmd (job_command_is_something_bonus.c:38)
==5605==    by 0x409745: process_sep (job_command_bonus.c:28)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 16 bytes in 1 blocks are still reachable in loss record 5 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x41077A: ft_lstnew (ft_lstnew.c:19)
==5605==    by 0x40A087: add_cmd_to_job (job_command_create_bonus.c:48)
==5605==    by 0x40AC0F: is_end_cmd (job_command_is_something_bonus.c:25)
==5605==    by 0x40AC7F: is_add_cmd (job_command_is_something_bonus.c:38)
==5605==    by 0x409745: process_sep (job_command_bonus.c:28)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 16 bytes in 1 blocks are still reachable in loss record 6 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x41077A: ft_lstnew (ft_lstnew.c:19)
==5605==    by 0x40A9F3: add_job_to_list (job_init_bonus.c:8)
==5605==    by 0x4097C4: process_sep (job_command_bonus.c:36)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 16 bytes in 1 blocks are still reachable in loss record 7 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40BCE0: clean_av (clean_redirection_bonus.c:52)
==5605==    by 0x40BC4A: clean_redir_av (clean_redirection_bonus.c:82)
==5605==    by 0x40BB9E: hub_process_redirection (process_redirection_bonus.c:7)
==5605==    by 0x40BA2F: process_redirection (process_redirection_bonus.c:21)
==5605==    by 0x40B5C9: is_redirection (cleaner_bonus.c:7)
==5605==    by 0x40B529: process_clean_command (cleaner_bonus.c:35)
==5605==    by 0x40B47F: cleaner (cleaner_bonus.c:82)
==5605==    by 0x40B754: process_cleaner (hub_cleaner_bonus.c:7)
==5605==    by 0x40B680: hub_cleaner (hub_cleaner_bonus.c:49)
==5605==    by 0x40180C: main (main_bonus.c:92)
==5605== 
==5605== 24 bytes in 1 blocks are still reachable in loss record 8 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40AA53: init_job (job_init_bonus.c:23)
==5605==    by 0x4096A2: process_sep (job_command_bonus.c:21)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 32 bytes in 1 blocks are still reachable in loss record 9 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x410A53: vct_new (vct_new.c:19)
==5605==    by 0x4113E1: vct_readline (vct_readline.c:41)
==5605==    by 0x40195D: read_loop (main_bonus.c:10)
==5605==    by 0x4017E8: main (main_bonus.c:81)
==5605== 
==5605== 144 bytes in 1 blocks are still reachable in loss record 10 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x409EEA: create_cmd (job_command_create_bonus.c:21)
==5605==    by 0x40A060: add_cmd_to_job (job_command_create_bonus.c:45)
==5605==    by 0x40AC0F: is_end_cmd (job_command_is_something_bonus.c:25)
==5605==    by 0x40AC7F: is_add_cmd (job_command_is_something_bonus.c:38)
==5605==    by 0x409745: process_sep (job_command_bonus.c:28)
==5605==    by 0x409642: get_jobs (job_command_bonus.c:71)
==5605==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==5605==    by 0x4019F9: process_minishell (main_bonus.c:42)
==5605==    by 0x4017F4: main (main_bonus.c:89)
==5605== 
==5605== 216 bytes in 1 blocks are still reachable in loss record 11 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x40F53D: ft_calloc (ft_calloc.c:22)
==5605==    by 0x4047B1: init_line_editor (init_line_editor_bonus.c:50)
==5605==    by 0x4017BC: main (main_bonus.c:73)
==5605== 
==5605== 2,048 bytes in 1 blocks are still reachable in loss record 12 of 12
==5605==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5605==    by 0x410A9A: vct_new (vct_new.c:25)
==5605==    by 0x4113E1: vct_readline (vct_readline.c:41)
==5605==    by 0x40195D: read_loop (main_bonus.c:10)
==5605==    by 0x4017E8: main (main_bonus.c:81)
==5605== 
==5605== LEAK SUMMARY:
==5605==    definitely lost: 0 bytes in 0 blocks
==5605==    indirectly lost: 0 bytes in 0 blocks
==5605==      possibly lost: 0 bytes in 0 blocks
==5605==    still reachable: 2,525 bytes in 12 blocks
==5605==         suppressed: 0 bytes in 0 blocks
==5605== 
==5605== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==5605== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
