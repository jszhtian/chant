using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace SampleGUI
{
    class StringMapClass
    {
        [DllImport("libbase.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        private extern static int base4096_decode(ref UInt16 data,  int length, ref byte result, int bufSize);
        [DllImport("libbase.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        private extern static int base4096_encode(ref byte data, int length, ref UInt16 result, int bufSize);
        char[] chars;
        public StringMapClass() {
            try {
                FileStream file = new FileStream("table.bin", FileMode.Open);
                long size = file.Length;
                byte[] array = new byte[size];
                file.Read(array, 0, array.Length);
                file.Close();
                chars = Encoding.Unicode.GetChars(array);
            }
            catch (IOException e)
            {
                System.Windows.MessageBox.Show(e.ToString(), "Error");
            }
        }
        public string StringEncoder(string input) {
            try {
                byte[] arr = Encoding.Default.GetBytes(input);
                UInt16[] res = new UInt16[512];
                int getLength=base4096_encode(ref arr[0], arr.Length, ref res[0], res.Length);
                string outputstring="";
                for (int i = 0; i < getLength; i++)
                {
                    if (res[i] == 0xF001)
                    {
                        outputstring = outputstring + "也";
                        continue;
                    }
                    if (res[i] == 0xF002)
                    {
                        outputstring = outputstring + "哉";
                        continue;
                    }
                    outputstring = outputstring + chars[res[i]];
                }
                return outputstring;
            }
            catch (Exception e)
            {
                System.Windows.MessageBox.Show(e.ToString(),"Error");
            }
            string ret = "ERROR";
            return ret;
        }

        public string StringDecoder(string input) {
            try
            {
                int count = 0;
                UInt16[] arr = new UInt16[512];
                foreach (char ch in input)
                {
                    if (string.Equals(ch, "哉"))
                    {
                        arr[count] = 0xF002;
                        goto ending;
                    }
                    if (string.Equals(ch, "也"))
                    {
                        arr[count] = 0xF001;
                        goto ending;
                    }
                    for (int i = 0; i < chars.Length; i++)
                    {
                        if (string.Equals(ch, chars[i]))
                        {
                            arr[count] = (UInt16)i;
                            break;
                        }
                    }
                    ending:
                    count += 1;
                }
                byte[] res = new byte[512];
                int getLength = base4096_decode(ref arr[0], count, ref res[0], res.Length);
                string outputstring = Encoding.Default.GetString(res);
                outputstring = outputstring.Substring(0, getLength);
                return outputstring;
            }
            catch (Exception e)
            {
                System.Windows.MessageBox.Show(e.ToString(),"Error");
            }
            string ret = "ERROR";
            return ret;

        }
    }
}
