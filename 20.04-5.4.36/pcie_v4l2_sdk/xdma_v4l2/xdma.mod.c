#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x2c635209, "module_layout" },
	{ 0xde6db12e, "vb2_ioctl_reqbufs" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x7a3848cc, "dma_map_sg_attrs" },
	{ 0x8006b741, "kmem_cache_destroy" },
	{ 0xd1f09b0c, "device_remove_file" },
	{ 0x37ce6741, "cdev_del" },
	{ 0x30a93ed, "kmalloc_caches" },
	{ 0xe78b9c02, "v4l2_event_unsubscribe" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x51b1c11d, "cdev_init" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc6c777de, "put_devmap_managed_page" },
	{ 0x5f664094, "pci_write_config_word" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcc364e2d, "pci_read_config_byte" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x4195c8ba, "v4l2_ctrl_log_status" },
	{ 0xcc2dfcaf, "dma_unmap_sg_attrs" },
	{ 0x9ae2ba2c, "video_device_release" },
	{ 0x42d723fb, "dma_set_mask" },
	{ 0x6595781a, "pcie_set_readrq" },
	{ 0xd033aa56, "boot_cpu_data" },
	{ 0x69449ab2, "pci_disable_device" },
	{ 0x59b96051, "v4l2_device_unregister" },
	{ 0xb335054a, "pci_disable_msix" },
	{ 0xc3231ec5, "set_page_dirty_lock" },
	{ 0xd35d627, "vb2_fop_poll" },
	{ 0x53a70082, "vb2_ioctl_streamon" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xdff7669f, "device_destroy" },
	{ 0x15a66331, "kobject_set_name" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x87b8798d, "sg_next" },
	{ 0x469a8847, "vb2_ops_wait_prepare" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xa0bcb084, "pci_release_regions" },
	{ 0x5ef6d8c1, "__video_register_device" },
	{ 0x1ab5d5b3, "pcie_capability_clear_and_set_word" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x999e8297, "vfree" },
	{ 0x46afdcba, "dma_free_attrs" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x71038ac7, "pv_ops" },
	{ 0x1e0252cf, "dma_set_coherent_mask" },
	{ 0x851c15cf, "kthread_create_on_node" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x9f4865da, "v4l2_device_register" },
	{ 0x3363cbcd, "kthread_bind" },
	{ 0x87bafcf0, "vb2_fop_read" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xaff2dd5d, "pci_set_master" },
	{ 0xf7242b1e, "pci_alloc_irq_vectors_affinity" },
	{ 0xfb578fc5, "memset" },
	{ 0x67a5e6fa, "video_device_alloc" },
	{ 0xe4d58f66, "pci_restore_state" },
	{ 0xba0915a3, "pci_iounmap" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6f961649, "vb2_fop_mmap" },
	{ 0xc445371b, "vb2_ioctl_qbuf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0xa0aa95d4, "kthread_stop" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x961a59ab, "video_unregister_device" },
	{ 0x67c090fb, "pci_aer_clear_nonfatal_status" },
	{ 0xc25ff407, "v4l2_ctrl_subscribe_event" },
	{ 0xc0c5c87, "vb2_buffer_done" },
	{ 0x23f3d4d7, "pci_read_config_word" },
	{ 0xce11de54, "dma_alloc_attrs" },
	{ 0x2e1637a6, "kmem_cache_free" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x711ee915, "finish_swait" },
	{ 0x4bcc8ea3, "vb2_ioctl_prepare_buf" },
	{ 0xcf2a881c, "device_create" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x658b887c, "vb2_ioctl_create_bufs" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xf0311d7, "_dev_err" },
	{ 0x56b2ac65, "pci_enable_msi" },
	{ 0xf49d7e54, "vb2_ioctl_dqbuf" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa76a035a, "pci_find_capability" },
	{ 0x9932471a, "device_create_file" },
	{ 0xabac4112, "cdev_add" },
	{ 0x800473f, "__cond_resched" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0xa2873fd9, "vb2_plane_cookie" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6c3777ff, "kmem_cache_alloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x618911fc, "numa_node" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xa916b694, "strnlen" },
	{ 0xcd891823, "vb2_fop_release" },
	{ 0x70fdba19, "video_devdata" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9cb986f2, "vmalloc_base" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xfdbe8876, "prepare_to_swait_event" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9ce84760, "wake_up_process" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1c937e3f, "pci_unregister_driver" },
	{ 0xaf88e69b, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4b1c40fe, "kmem_cache_create" },
	{ 0x640663dd, "pci_irq_vector" },
	{ 0x39be654e, "v4l2_fh_open" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x16b35c66, "vb2_ioctl_querybuf" },
	{ 0x37a0cba, "kfree" },
	{ 0x7394b519, "remap_pfn_range" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe3f4c62c, "pci_request_regions" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x43ea87ab, "pci_disable_msi" },
	{ 0x2554c13b, "__pci_register_driver" },
	{ 0x3ee2b36d, "class_destroy" },
	{ 0x5c32afb6, "vb2_ops_wait_finish" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x21531b59, "pci_iomap" },
	{ 0x5ac5f4cc, "pci_enable_device_mem" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xb3a3422c, "vb2_ioctl_streamoff" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xa74ccb9b, "pci_enable_device" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x7a08b1ac, "param_ops_uint" },
	{ 0x921475e, "v4l2_device_put" },
	{ 0x9b0fb107, "__class_create" },
	{ 0x92412c55, "video_ioctl2" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd54fe6d2, "__put_page" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xec925c6d, "get_user_pages_fast" },
	{ 0xc80ab559, "swake_up_one" },
	{ 0xf3e7ad95, "vb2_dma_sg_memops" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x738b5529, "pci_save_state" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xc7533a61, "vb2_queue_init" },
	{ 0x8a35b432, "sme_me_mask" },
};

MODULE_INFO(depends, "videobuf2-v4l2,videodev,videobuf2-common,videobuf2-dma-sg");

MODULE_ALIAS("pci:v000010EEd00009048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000903Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00008038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00007038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006828sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006830sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006928sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006930sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006A28sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006A30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006D30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00004808sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00004828sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00004908sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00004A28sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00004B28sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00002808sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd0000F000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001D0Fd0000F001sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "2052D71FEEB543F889EA9A5");
