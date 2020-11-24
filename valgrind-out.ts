==16263== Memcheck, a memory error detector
==16263== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==16263== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==16263== Command: ./Minishell
==16263== Parent PID: 16142
==16263== 
--16263-- 
--16263-- Valgrind options:
--16263--    --leak-check=full
--16263--    --show-leak-kinds=all
--16263--    --track-origins=yes
--16263--    --verbose
--16263--    --log-file=valgrind-out.ts
--16263-- Contents of /proc/version:
--16263--   Linux version 5.4.0-52-generic (buildd@lcy01-amd64-022) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #57~18.04.1-Ubuntu SMP Thu Oct 15 14:04:49 UTC 2020
--16263-- 
--16263-- Arch and hwcaps: AMD64, LittleEndian, amd64-cx16-rdtscp-sse3-avx
--16263-- Page sizes: currently 4096, max supported 4096
--16263-- Valgrind library directory: /usr/lib/valgrind
--16263-- Reading syms from /home/user42/42/minishell/REPO/Minishell
--16263-- Reading syms from /lib/x86_64-linux-gnu/ld-2.27.so
--16263--   Considering /lib/x86_64-linux-gnu/ld-2.27.so ..
--16263--   .. CRC mismatch (computed ac9397f6 wanted d0d82632)
--16263--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/ld-2.27.so ..
--16263--   .. CRC is valid
--16263-- Reading syms from /usr/lib/valgrind/memcheck-amd64-linux
--16263--   Considering /usr/lib/valgrind/memcheck-amd64-linux ..
--16263--   .. CRC mismatch (computed 41ddb025 wanted 9972f546)
--16263--    object doesn't have a symbol table
--16263--    object doesn't have a dynamic symbol table
--16263-- Scheduler: using generic scheduler lock implementation.
--16263-- Reading suppressions file: /usr/lib/valgrind/default.supp
==16263== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-16263-by-user42-on-???
==16263== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-16263-by-user42-on-???
==16263== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-16263-by-user42-on-???
==16263== 
==16263== TO CONTROL THIS PROCESS USING vgdb (which you probably
==16263== don't want to do, unless you know exactly what you're doing,
==16263== or are doing some strange experiment):
==16263==   /usr/lib/valgrind/../../bin/vgdb --pid=16263 ...command...
==16263== 
==16263== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==16263==   /path/to/gdb ./Minishell
==16263== and then give GDB the following command
==16263==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=16263
==16263== --pid is optional if only one valgrind process is running
==16263== 
--16263-- REDIR: 0x401f320 (ld-linux-x86-64.so.2:strlen) redirected to 0x580608c1 (???)
--16263-- REDIR: 0x401f100 (ld-linux-x86-64.so.2:index) redirected to 0x580608db (???)
--16263-- Reading syms from /usr/lib/valgrind/vgpreload_core-amd64-linux.so
--16263--   Considering /usr/lib/valgrind/vgpreload_core-amd64-linux.so ..
--16263--   .. CRC mismatch (computed 50df1b30 wanted 4800a4cf)
--16263--    object doesn't have a symbol table
--16263-- Reading syms from /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so
--16263--   Considering /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so ..
--16263--   .. CRC mismatch (computed f893b962 wanted 95ee359e)
--16263--    object doesn't have a symbol table
==16263== WARNING: new redirection conflicts with existing -- ignoring it
--16263--     old: 0x0401f320 (strlen              ) R-> (0000.0) 0x580608c1 ???
--16263--     new: 0x0401f320 (strlen              ) R-> (2007.0) 0x04c32db0 strlen
--16263-- REDIR: 0x401d390 (ld-linux-x86-64.so.2:strcmp) redirected to 0x4c33ee0 (strcmp)
--16263-- REDIR: 0x401f860 (ld-linux-x86-64.so.2:mempcpy) redirected to 0x4c374f0 (mempcpy)
--16263-- Reading syms from /lib/x86_64-linux-gnu/libncurses.so.5.9
--16263--    object doesn't have a symbol table
--16263-- Reading syms from /lib/x86_64-linux-gnu/libtinfo.so.5.9
--16263--    object doesn't have a symbol table
--16263-- Reading syms from /lib/x86_64-linux-gnu/libc-2.27.so
--16263--   Considering /lib/x86_64-linux-gnu/libc-2.27.so ..
--16263--   .. CRC mismatch (computed c2c067b2 wanted d73adc7f)
--16263--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libc-2.27.so ..
--16263--   .. CRC is valid
--16263-- Reading syms from /lib/x86_64-linux-gnu/libdl-2.27.so
--16263--   Considering /lib/x86_64-linux-gnu/libdl-2.27.so ..
--16263--   .. CRC mismatch (computed 415bd007 wanted 4d6f4a12)
--16263--   Considering /usr/lib/debug/lib/x86_64-linux-gnu/libdl-2.27.so ..
--16263--   .. CRC is valid
--16263-- REDIR: 0x5327ce0 (libc.so.6:memmove) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326db0 (libc.so.6:strncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327fc0 (libc.so.6:strcasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326800 (libc.so.6:strcat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326de0 (libc.so.6:rindex) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5329830 (libc.so.6:rawmemchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327e50 (libc.so.6:mempcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327c80 (libc.so.6:bcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326d70 (libc.so.6:strncmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326870 (libc.so.6:strcmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327db0 (libc.so.6:memset) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5345160 (libc.so.6:wcschr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326d10 (libc.so.6:strnlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x53268e0 (libc.so.6:strcspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5328010 (libc.so.6:strncasecmp) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x53268b0 (libc.so.6:strcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5328150 (libc.so.6:memcpy@@GLIBC_2.14) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326e10 (libc.so.6:strpbrk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326830 (libc.so.6:index) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326ce0 (libc.so.6:strlen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5331730 (libc.so.6:memrchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5328060 (libc.so.6:strcasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327c50 (libc.so.6:memchr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5345f20 (libc.so.6:wcslen) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x53270c0 (libc.so.6:strspn) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327f90 (libc.so.6:stpncpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327f60 (libc.so.6:stpcpy) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5329860 (libc.so.6:strchrnul) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x53280b0 (libc.so.6:strncasecmp_l) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5326d40 (libc.so.6:strncat) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x53baa50 (libc.so.6:__memcpy_chk) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x5327b90 (libc.so.6:strstr) redirected to 0x4a2a6e0 (_vgnU_ifunc_wrapper)
--16263-- REDIR: 0x533a3a0 (libc.so.6:__strrchr_sse2) redirected to 0x4c32790 (__strrchr_sse2)
--16263-- REDIR: 0x53200e0 (libc.so.6:malloc) redirected to 0x4c2faa0 (malloc)
--16263-- REDIR: 0x53209c0 (libc.so.6:free) redirected to 0x4c30cd0 (free)
==17392== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17392-by-user42-on-???
==17392== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17392-by-user42-on-???
==17392== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17392-by-user42-on-???
==17392== 
==17392== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17392== don't want to do, unless you know exactly what you're doing,
==17392== or are doing some strange experiment):
==17392==   /usr/lib/valgrind/../../bin/vgdb --pid=17392 ...command...
==17392== 
==17392== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17392==   /path/to/gdb ./Minishell
==17392== and then give GDB the following command
==17392==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17392
==17392== --pid is optional if only one valgrind process is running
==17392== 
==17629== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17629-by-user42-on-???
==17629== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17629-by-user42-on-???
==17629== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17629-by-user42-on-???
==17629== 
==17629== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17629== don't want to do, unless you know exactly what you're doing,
==17629== or are doing some strange experiment):
==17629==   /usr/lib/valgrind/../../bin/vgdb --pid=17629 ...command...
==17629== 
==17629== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17629==   /path/to/gdb ./Minishell
==17629== and then give GDB the following command
==17629==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17629
==17629== --pid is optional if only one valgrind process is running
==17629== 
==17628== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17628-by-user42-on-???
==17628== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17628-by-user42-on-???
==17628== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17628-by-user42-on-???
==17628== 
==17628== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17628== don't want to do, unless you know exactly what you're doing,
==17628== or are doing some strange experiment):
==17628==   /usr/lib/valgrind/../../bin/vgdb --pid=17628 ...command...
==17628== 
==17628== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17628==   /path/to/gdb ./Minishell
==17628== and then give GDB the following command
==17628==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17628
==17628== --pid is optional if only one valgrind process is running
==17628== 
==17630== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17630-by-user42-on-???
==17630== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17630-by-user42-on-???
==17630== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17630-by-user42-on-???
==17630== 
==17630== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17630== don't want to do, unless you know exactly what you're doing,
==17630== or are doing some strange experiment):
==17630==   /usr/lib/valgrind/../../bin/vgdb --pid=17630 ...command...
==17630== 
==17630== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17630==   /path/to/gdb ./Minishell
==17630== and then give GDB the following command
==17630==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17630
==17630== --pid is optional if only one valgrind process is running
==17630== 
==17873== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17873-by-user42-on-???
==17873== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17873-by-user42-on-???
==17873== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17873-by-user42-on-???
==17873== 
==17873== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17873== don't want to do, unless you know exactly what you're doing,
==17873== or are doing some strange experiment):
==17873==   /usr/lib/valgrind/../../bin/vgdb --pid=17873 ...command...
==17873== 
==17873== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17873==   /path/to/gdb ./Minishell
==17873== and then give GDB the following command
==17873==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17873
==17873== --pid is optional if only one valgrind process is running
==17873== 
==17874== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17874-by-user42-on-???
==17874== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17874-by-user42-on-???
==17874== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17874-by-user42-on-???
==17874== 
==17874== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17874== don't want to do, unless you know exactly what you're doing,
==17874== or are doing some strange experiment):
==17874==   /usr/lib/valgrind/../../bin/vgdb --pid=17874 ...command...
==17874== 
==17874== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17874==   /path/to/gdb ./Minishell
==17874== and then give GDB the following command
==17874==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17874
==17874== --pid is optional if only one valgrind process is running
==17874== 
==17875== embedded gdbserver: reading from /tmp/vgdb-pipe-from-vgdb-to-17875-by-user42-on-???
==17875== embedded gdbserver: writing to   /tmp/vgdb-pipe-to-vgdb-from-17875-by-user42-on-???
==17875== embedded gdbserver: shared mem   /tmp/vgdb-pipe-shared-mem-vgdb-17875-by-user42-on-???
==17875== 
==17875== TO CONTROL THIS PROCESS USING vgdb (which you probably
==17875== don't want to do, unless you know exactly what you're doing,
==17875== or are doing some strange experiment):
==17875==   /usr/lib/valgrind/../../bin/vgdb --pid=17875 ...command...
==17875== 
==17875== TO DEBUG THIS PROCESS USING GDB: start GDB like this
==17875==   /path/to/gdb ./Minishell
==17875== and then give GDB the following command
==17875==   target remote | /usr/lib/valgrind/../../bin/vgdb --pid=17875
==17875== --pid is optional if only one valgrind process is running
==17875== 
--16263-- REDIR: 0x53444d0 (libc.so.6:memcpy@GLIBC_2.2.5) redirected to 0x4c34060 (memcpy@GLIBC_2.2.5)
==16263== 
==16263== HEAP SUMMARY:
==16263==     in use at exit: 2,525 bytes in 12 blocks
==16263==   total heap usage: 775 allocs, 763 frees, 335,623 bytes allocated
==16263== 
==16263== Searching for pointers to 12 not-freed blocks
==16263== Checked 80,408 bytes
==16263== 
==16263== 0 bytes in 1 blocks are still reachable in loss record 1 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40A532: fill_assign (job_command_fill_bonus.c:38)
==16263==    by 0x40B204: resize_cmd (job_command_create_utils_bonus.c:17)
==16263==    by 0x40A27F: fill_cmd_model (job_command_create_bonus.c:96)
==16263==    by 0x40AC1D: is_end_cmd (job_command_is_something_bonus.c:23)
==16263==    by 0x40ACAF: is_add_cmd (job_command_is_something_bonus.c:38)
==16263==    by 0x409775: process_sep (job_command_bonus.c:28)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 0 bytes in 1 blocks are still reachable in loss record 2 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40A5E2: fill_exp (job_command_fill_bonus.c:59)
==16263==    by 0x40B22A: resize_cmd (job_command_create_utils_bonus.c:19)
==16263==    by 0x40A27F: fill_cmd_model (job_command_create_bonus.c:96)
==16263==    by 0x40AC1D: is_end_cmd (job_command_is_something_bonus.c:23)
==16263==    by 0x40ACAF: is_add_cmd (job_command_is_something_bonus.c:38)
==16263==    by 0x409775: process_sep (job_command_bonus.c:28)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 5 bytes in 1 blocks are still reachable in loss record 3 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40FE4C: ft_strdup (ft_strdup.c:21)
==16263==    by 0x40BD90: clean_av (clean_redirection_bonus.c:59)
==16263==    by 0x40BC7A: clean_redir_av (clean_redirection_bonus.c:82)
==16263==    by 0x40BBCE: hub_process_redirection (process_redirection_bonus.c:7)
==16263==    by 0x40BA5F: process_redirection (process_redirection_bonus.c:21)
==16263==    by 0x40B5F9: is_redirection (cleaner_bonus.c:7)
==16263==    by 0x40B559: process_clean_command (cleaner_bonus.c:35)
==16263==    by 0x40B4AF: cleaner (cleaner_bonus.c:82)
==16263==    by 0x40B784: process_cleaner (hub_cleaner_bonus.c:7)
==16263==    by 0x40B6B0: hub_cleaner (hub_cleaner_bonus.c:49)
==16263==    by 0x40180C: main (main_bonus.c:92)
==16263== 
==16263== 8 bytes in 1 blocks are still reachable in loss record 4 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40A409: fill_name (job_command_fill_bonus.c:13)
==16263==    by 0x40B2C4: fill_data_cmd (job_command_create_utils_bonus.c:34)
==16263==    by 0x40A349: fill_cmd_model (job_command_create_bonus.c:111)
==16263==    by 0x40ABF1: is_end_cmd (job_command_is_something_bonus.c:20)
==16263==    by 0x40ACAF: is_add_cmd (job_command_is_something_bonus.c:38)
==16263==    by 0x409775: process_sep (job_command_bonus.c:28)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 16 bytes in 1 blocks are still reachable in loss record 5 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x4107AA: ft_lstnew (ft_lstnew.c:19)
==16263==    by 0x40A0B7: add_cmd_to_job (job_command_create_bonus.c:48)
==16263==    by 0x40AC3F: is_end_cmd (job_command_is_something_bonus.c:25)
==16263==    by 0x40ACAF: is_add_cmd (job_command_is_something_bonus.c:38)
==16263==    by 0x409775: process_sep (job_command_bonus.c:28)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 16 bytes in 1 blocks are still reachable in loss record 6 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x4107AA: ft_lstnew (ft_lstnew.c:19)
==16263==    by 0x40AA23: add_job_to_list (job_init_bonus.c:8)
==16263==    by 0x4097F4: process_sep (job_command_bonus.c:36)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 16 bytes in 1 blocks are still reachable in loss record 7 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40BD10: clean_av (clean_redirection_bonus.c:52)
==16263==    by 0x40BC7A: clean_redir_av (clean_redirection_bonus.c:82)
==16263==    by 0x40BBCE: hub_process_redirection (process_redirection_bonus.c:7)
==16263==    by 0x40BA5F: process_redirection (process_redirection_bonus.c:21)
==16263==    by 0x40B5F9: is_redirection (cleaner_bonus.c:7)
==16263==    by 0x40B559: process_clean_command (cleaner_bonus.c:35)
==16263==    by 0x40B4AF: cleaner (cleaner_bonus.c:82)
==16263==    by 0x40B784: process_cleaner (hub_cleaner_bonus.c:7)
==16263==    by 0x40B6B0: hub_cleaner (hub_cleaner_bonus.c:49)
==16263==    by 0x40180C: main (main_bonus.c:92)
==16263== 
==16263== 24 bytes in 1 blocks are still reachable in loss record 8 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40AA83: init_job (job_init_bonus.c:23)
==16263==    by 0x4096D2: process_sep (job_command_bonus.c:21)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 32 bytes in 1 blocks are still reachable in loss record 9 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x410A83: vct_new (vct_new.c:19)
==16263==    by 0x411411: vct_readline (vct_readline.c:41)
==16263==    by 0x40195D: read_loop (main_bonus.c:10)
==16263==    by 0x4017E8: main (main_bonus.c:81)
==16263== 
==16263== 144 bytes in 1 blocks are still reachable in loss record 10 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x409F1A: create_cmd (job_command_create_bonus.c:21)
==16263==    by 0x40A090: add_cmd_to_job (job_command_create_bonus.c:45)
==16263==    by 0x40AC3F: is_end_cmd (job_command_is_something_bonus.c:25)
==16263==    by 0x40ACAF: is_add_cmd (job_command_is_something_bonus.c:38)
==16263==    by 0x409775: process_sep (job_command_bonus.c:28)
==16263==    by 0x409672: get_jobs (job_command_bonus.c:71)
==16263==    by 0x401EE4: test_jobs (test_jobs_bonus.c:99)
==16263==    by 0x4019F9: process_minishell (main_bonus.c:42)
==16263==    by 0x4017F4: main (main_bonus.c:89)
==16263== 
==16263== 216 bytes in 1 blocks are still reachable in loss record 11 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x40F56D: ft_calloc (ft_calloc.c:22)
==16263==    by 0x4047B1: init_line_editor (init_line_editor_bonus.c:50)
==16263==    by 0x4017BC: main (main_bonus.c:73)
==16263== 
==16263== 2,048 bytes in 1 blocks are still reachable in loss record 12 of 12
==16263==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==16263==    by 0x410ACA: vct_new (vct_new.c:25)
==16263==    by 0x411411: vct_readline (vct_readline.c:41)
==16263==    by 0x40195D: read_loop (main_bonus.c:10)
==16263==    by 0x4017E8: main (main_bonus.c:81)
==16263== 
==16263== LEAK SUMMARY:
==16263==    definitely lost: 0 bytes in 0 blocks
==16263==    indirectly lost: 0 bytes in 0 blocks
==16263==      possibly lost: 0 bytes in 0 blocks
==16263==    still reachable: 2,525 bytes in 12 blocks
==16263==         suppressed: 0 bytes in 0 blocks
==16263== 
==16263== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==16263== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
