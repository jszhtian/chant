using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
namespace SampleGUI
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void EncButton_Click(object sender, RoutedEventArgs e)
        {
            StringMapClass Map = new StringMapClass();
            string result=Map.StringEncoder(InputText.Text);
            ResultText.Text = result;
        }

        private void DecButton_Click(object sender, RoutedEventArgs e)
        {
            StringMapClass Map = new StringMapClass();
            string result = Map.StringDecoder(InputText.Text);
            ResultText.Text = result;
        }
    }
}
