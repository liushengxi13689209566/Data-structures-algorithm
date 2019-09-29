/*/*
 * This creates a new process as a copy of the old one,
 * but does not actually start it yet.
 * 根据clone_flags标志拷贝寄存器，以及其他进程环境
 * It copies the registers, and all the appropriate(适当)
 * parts of the process environment (as per the clone
 * flags). The actual kick-off is left to the caller. 
 * 搞好的这个新的进程的启动由调用者完成启动 
 */
task_struct *copy_process(unsigned long clone_flags,
                          unsigned long stack_start,
                          struct pt_regs *regs,
                          unsigned long stack_size,
                          int __user *child_tidptr,
                          struct pid *pid,
                          int trace)
{
  struct task_struct *p;
  //1.复制进程内核栈(thread_info)和进程描述符结构
  p = dup_task_struct(current);
  //2.一些相关处理
  。。。 shm_init_task(p);
  security_task_alloc(p, clone_flags);
  //3.复制父进程的所有数据结构
  copy_semundo(clone_flags, p);
  copy_files(clone_flags, p);
  copy_fs(clone_flags, p);
  copy_sighand(clone_flags, p);
  copy_signal(clone_flags, p);
  copy_mm(clone_flags, p);
  copy_namespaces(clone_flags, p);
  copy_io(clone_flags, p);
  //4.初始化子进程的内核栈。将寄存器%eax置为0，也是子进程pid返回0的原因
  copy_thread_tls(clone_flags, args->stack, args->stack_size, p,
                  args->tls);

  stackleak_task_init(p);
  pid = alloc_pid(p->nsproxy->pid_ns_for_children); //分配新的 Pid
  //设置子进程的 pid
  p->pid = pid_nr(pid);
  //如果是创建线程
  if (clone_flags & CLONE_THREAD)
  {
    p->exit_signal = -1;
    p->group_leader = current->group_leader;
    //tgid 是当前线程组的 id
    p->tgid = current->tgid;
  }
  else
  {
    if (clone_flags & CLONE_PARENT)
      p->exit_signal = current->group_leader->exit_signal;
    else
      p->exit_signal = (clone_flags & CSIGNAL);
    p->group_leader = p;
    p->tgid = p->pid;
  }

  if (clone_flags & (CLONE_PARENT | CLONE_THREAD))
  {
    //如果是创建线程，那么同一线程组内的所有线程共享进程空间
    p->real_parent = current->real_parent;
    p->parent_exec_id = current->parent_exec_id;
  }
  else
  {
    //如果是创建进程，当前进程就是子进程的父进程
    p->real_parent = current;
    p->parent_exec_id = current->self_exec_id;
  }

  attach_pid(p, PIDTYPE_PID);
  nr_threads++;

  //返回被创建的 task 结构体指针
  return p;
}