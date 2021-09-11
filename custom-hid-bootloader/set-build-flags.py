from platform import system
Import("env")

# please keep $SOURCE variable, it will be replaced with a path to firmware
print("edited build_flags")
# print("Before")
# print(str(env['CPPDEFINES']))

env['CPPDEFINES'].remove(('VECT_TAB_ADDR', '0x8000000'))
env['CPPDEFINES'].remove('SERIAL_USB')
env['CPPDEFINES'].remove(('CONFIG_MAPLE_MINI_NO_DISABLE_DEBUG', 1))

env['CPPDEFINES'].append(('GENERIC_BOOTLOADER',))
env['CPPDEFINES'].append(('VECT_TAB_ADDR', '0x8000800'))
# print("After")
print(str(env['CPPDEFINES']))

if system() == "Windows":
    upload_exec_file = "\\windows\\hid-flash.exe"
elif system() == "Darwin":
    upload_exec_file = "/macos/hid-flash"
else:
    upload_exec_file = "/linux/hid-flash"

env.Replace(
    UPLOADER='custom-hid-bootloader' + upload_exec_file,
    UPLOADCMD='$UPLOADER $SOURCE'
)
