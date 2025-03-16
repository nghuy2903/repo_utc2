using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ListViewExamle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            

            // Thêm các cột vào ListView
            lvSanPham.Columns.Add("Mã SP", 100);
            lvSanPham.Columns.Add("Tên SP", 200);
            lvSanPham.Columns.Add("Giá SP", 300);

            // Thiết lập thuộc tính để tự động chỉnh sửa kích thước cột
            lvSanPham.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private void lvSanPham_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            // Lấy thông tin từ các TextBox
            string maSP = txtMaSP1.Text;
            string tenSP = txtTenSP1.Text;
            string giaSP = txtGiaSP1.Text;

            // Tạo một mảng để chứa các thông tin của sản phẩm
            string[] row = { maSP, tenSP, giaSP };

            // Tạo một ListViewItem mới và thêm vào ListView
            var listViewItem = new ListViewItem(row);
            lvSanPham.Items.Add(listViewItem);

            // Xóa nội dung của TextBox sau khi thêm
            txtMaSP1.Clear();
            txtTenSP1.Clear();
            txtGiaSP1.Clear();
        }

        private void txtMaSP_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtTenSp_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtGiaSp_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtTenSP_Click(object sender, EventArgs e)
        {

        }
    }
}
