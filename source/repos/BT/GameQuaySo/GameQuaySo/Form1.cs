using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameQuaySo
{
    public partial class Form1 : Form
    {
        private int currentLabelIndex = 0;
        private Random random = new Random();
        public Form1()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Sử lý sự kiện random số từ 1 đến 10 và số hiện lần lượt trong 3 label
            // Lấy số ngẫu nhiên từ 1 đến 10
            int randomNumber = random.Next(1, 11);

            
            switch (currentLabelIndex)
            {
                case 0:
                    label1.Text = randomNumber.ToString();
                    break;
                case 1:
                    label2.Text = randomNumber.ToString();
                    break;
                case 2:
                    label3.Text = randomNumber.ToString();
                    break;
            }

            
            currentLabelIndex = (currentLabelIndex + 1) % 3;
        }

        

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnTienHien_TextChanged(object sender, EventArgs e)
        {
            btnTienHien.Text = "100";
        }
    }
}
