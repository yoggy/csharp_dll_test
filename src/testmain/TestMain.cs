using System;

namespace testmain
{
    class TestMain
    {
        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern void PrintDebugInfo();

        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern IntPtr CreateBuffer(Int32 size);

        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern IntPtr FillBuffer(IntPtr buf, Int32 size);

        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern IntPtr SetBuffer(IntPtr buf, Int32 size, byte c);

        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern IntPtr PrintBuffer(IntPtr buf, Int32 size);

        [System.Runtime.InteropServices.DllImport("testlib")]
        private static extern void ReleaseBuffer(IntPtr buf);

        [System.Runtime.InteropServices.DllImport("kernel32", SetLastError = true)]
        private static extern bool SetDllDirectory(string lpPathName);

        static void SetupDllDirectory()
        {
            string exe_path = System.IO.Path.GetDirectoryName(
                System.Reflection.Assembly.GetEntryAssembly().Location);

            string path;
            if (System.Environment.Is64BitProcess)
            {
#if DEBUG
                path = exe_path + @"\dll\x64\Debug";
#else
                path = exe_path + @"\dll\x64\Release";
#endif
            }
            else
            {
#if DEBUG
                path = exe_path + @"\dll\Win32\Debug";
#else
                path = exe_path + @"\dll\Win32\Release";
#endif
            }
            SetDllDirectory(path);
        }

        static void Main(string[] args)
        {
            SetupDllDirectory();

            PrintDebugInfo();

            IntPtr buf = CreateBuffer(5);
            SetBuffer(buf, 5, 0x7a);
            PrintBuffer(buf, 5);
            ReleaseBuffer(buf);
            buf = IntPtr.Zero;
        }
    }
}
