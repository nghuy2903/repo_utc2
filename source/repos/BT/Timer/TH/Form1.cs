using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TH
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //Định dạng 05/10/2024 - 07: 38 : 20
            
            DateTime now = DateTime.Now;

            
            string formattedDateTime = now.ToString("dd/MM/yyyy - HH:mm:ss");

            
            label1.Text = formattedDateTime;
        }
    }
}
