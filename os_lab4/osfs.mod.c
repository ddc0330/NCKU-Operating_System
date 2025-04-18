#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

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



static const char ____versions[]
__used __section("__versions") =
	"\x1c\x00\x00\x00\xa9\xf2\x7c\xe5"
	"inode_init_owner\0\0\0\0"
	"\x1c\x00\x00\x00\x48\x9f\xdb\x88"
	"__check_object_size\0"
	"\x18\x00\x00\x00\x57\xe9\xa6\xca"
	"d_instantiate\0\0\0"
	"\x18\x00\x00\x00\xc2\x9c\xc4\x13"
	"_copy_from_user\0"
	"\x14\x00\x00\x00\x44\xa5\x2d\x29"
	"new_inode\0\0\0"
	"\x20\x00\x00\x00\x49\x0e\x55\xfa"
	"unregister_filesystem\0\0\0"
	"\x18\x00\x00\x00\x41\xd5\x2d\x17"
	"simple_statfs\0\0\0"
	"\x14\x00\x00\x00\x61\x1b\xa4\xe6"
	"d_make_root\0"
	"\x18\x00\x00\x00\xed\x32\x17\xb4"
	"d_splice_alias\0\0"
	"\x18\x00\x00\x00\x3a\x09\x07\x84"
	"current_time\0\0\0\0"
	"\x10\x00\x00\x00\xf4\x5e\x37\xdf"
	"iput\0\0\0\0"
	"\x1c\x00\x00\x00\x8b\xfe\x0d\xb4"
	"register_filesystem\0"
	"\x18\x00\x00\x00\x64\xbd\x8f\xba"
	"_raw_spin_lock\0\0"
	"\x18\x00\x00\x00\x8c\x89\xd4\xcb"
	"fortify_panic\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x20\x00\x00\x00\x02\x14\x3b\x49"
	"simple_inode_init_ts\0\0\0\0"
	"\x24\x00\x00\x00\x97\x70\x48\x65"
	"__x86_indirect_thunk_rax\0\0\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x14\x00\x00\x00\x92\x41\xbf\x71"
	"make_kuid\0\0\0"
	"\x10\x00\x00\x00\x94\xb6\x16\xa9"
	"strnlen\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x14\x00\x00\x00\xb0\x76\x23\x1f"
	"set_nlink\0\0\0"
	"\x10\x00\x00\x00\x11\x13\x92\x5a"
	"strncmp\0"
	"\x14\x00\x00\x00\x09\xa4\x97\x39"
	"from_kgid\0\0\0"
	"\x10\x00\x00\x00\xda\xfa\x66\x91"
	"strncpy\0"
	"\x18\x00\x00\x00\xea\x1f\xe4\x7f"
	"default_llseek\0\0"
	"\x14\x00\x00\x00\x1d\xac\x6d\x62"
	"from_kuid\0\0\0"
	"\x10\x00\x00\x00\xc5\x8f\x57\xfb"
	"memset\0\0"
	"\x24\x00\x00\x00\x2a\x9b\x54\x31"
	"__x86_indirect_thunk_r10\0\0\0\0"
	"\x1c\x00\x00\x00\x20\xb2\x12\xf8"
	"__insert_inode_hash\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\xe1\xbe\x10\x6b"
	"_copy_to_user\0\0\0"
	"\x14\x00\x00\x00\xdd\xb1\x6b\xc8"
	"make_kgid\0\0\0"
	"\x14\x00\x00\x00\x44\x80\xdd\x6a"
	"mount_nodev\0"
	"\x10\x00\x00\x00\x97\x82\x9e\x99"
	"vfree\0\0\0"
	"\x20\x00\x00\x00\x3a\x1d\x9b\xdc"
	"generic_delete_inode\0\0\0\0"
	"\x1c\x00\x00\x00\x2d\x07\x8a\x85"
	"generic_file_open\0\0\0"
	"\x10\x00\x00\x00\x8f\x68\xee\xd6"
	"vmalloc\0"
	"\x1c\x00\x00\x00\x65\x16\x91\x7f"
	"__mark_inode_dirty\0\0"
	"\x1c\x00\x00\x00\xab\xbf\x77\xb3"
	"generic_file_llseek\0"
	"\x1c\x00\x00\x00\x34\x4b\xb5\xb5"
	"_raw_spin_unlock\0\0\0\0"
	"\x18\x00\x00\x00\x56\x41\x31\xbc"
	"nop_mnt_idmap\0\0\0"
	"\x18\x00\x00\x00\x3a\x0a\xd8\xfc"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7EAB2D4AFD56F280CFB75E2");
