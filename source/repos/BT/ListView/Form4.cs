using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsAppB4
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {

        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtId.Text) || string.IsNullOrEmpty(txtName.Text) || string.IsNullOrEmpty(txtPrice.Text))
            {
                MessageBox.Show("Please enter all information");
            }
            else
            {
                ListViewItem lv1 = new ListViewItem(txtId.Text);
                lv1.SubItems.Add(txtName.Text);
                lv1.SubItems.Add(txtPrice.Text);
                listView1.Items.Add(lv1);

            }
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                listView1.Items.RemoveAt(listView1.SelectedItems[0].Index);

            }
        }

        private void btnRemoveAll_Click(object sender, EventArgs e)
        {
            while (listView1.SelectedItems.Count > 0)
            {
                listView1.Items.Remove(listView1.SelectedItems[0]);

            }
        }

        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                contextMenuStrip1.Show(listView1, new Point(e.X, e.Y));
            }
        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {

            ListViewItem lv1 = listView1.SelectedItems[0];
            txtId.Text = lv1.Text;
            txtName.Text = lv1.SubItems[1].Text;
            txtPrice.Text = lv1.SubItems[2].Text;

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(txtId.Text) || string.IsNullOrEmpty(txtName.Text) || string.IsNullOrEmpty(txtPrice.Text))
            {
                MessageBox.Show("Please enter all information");
            }
            else
            {
                ListViewItem lv1 = listView1.SelectedItems[0];
                lv1.SubItems[0].Text = txtId.Text;
                lv1.SubItems[1].Text = txtName.Text;
                lv1.SubItems[2].Text = txtPrice.Text;

            }
        }

        private void removeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count > 0)
            {
                MessageBoxButtons buttons = MessageBoxButtons.YesNoCancel;
                DialogResult dialogResult = MessageBox.Show(
                    " 1 To remove product click yes button \n 2 On converse click no button or cancel button", "Confirm remove product", buttons, MessageBoxIcon.Information 
                    );
                if (dialogResult == DialogResult.Yes)
                {
                     listView1.Items.RemoveAt(listView1.SelectedItems[0].Index);
                    MessageBox.Show("Remove success");

                }
                else
                {
                    MessageBox.Show("Exit the notice success");
                }


            }
        }
    }
}
