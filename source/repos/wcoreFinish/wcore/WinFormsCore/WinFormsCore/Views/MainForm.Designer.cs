namespace WinFormsCore.Views
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            groupBox1 = new GroupBox();
            btnPrintCustomer = new Button();
            cmbFilter = new ComboBox();
            label10 = new Label();
            txbSearch = new TextBox();
            label9 = new Label();
            radioGiam = new RadioButton();
            radioTang = new RadioButton();
            label8 = new Label();
            lstTable = new ListView();
            lblPage = new Label();
            btnNextPage = new Button();
            btnBackPage = new Button();
            cmbLine = new ComboBox();
            label7 = new Label();
            cmbTinhTp = new ComboBox();
            btnCapNhat = new Button();
            btnThemMoi = new Button();
            txtPhone = new TextBox();
            label6 = new Label();
            label5 = new Label();
            txtQuocGia = new TextBox();
            label4 = new Label();
            label3 = new Label();
            txtTen = new TextBox();
            label2 = new Label();
            label1 = new Label();
            txtHo = new TextBox();
            contextMenuStrip1 = new ContextMenuStrip(components);
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(btnPrintCustomer);
            groupBox1.Controls.Add(cmbFilter);
            groupBox1.Controls.Add(label10);
            groupBox1.Controls.Add(txbSearch);
            groupBox1.Controls.Add(label9);
            groupBox1.Controls.Add(radioGiam);
            groupBox1.Controls.Add(radioTang);
            groupBox1.Controls.Add(label8);
            groupBox1.Controls.Add(lstTable);
            groupBox1.Controls.Add(lblPage);
            groupBox1.Controls.Add(btnNextPage);
            groupBox1.Controls.Add(btnBackPage);
            groupBox1.Controls.Add(cmbLine);
            groupBox1.Controls.Add(label7);
            groupBox1.Controls.Add(cmbTinhTp);
            groupBox1.Controls.Add(btnCapNhat);
            groupBox1.Controls.Add(btnThemMoi);
            groupBox1.Controls.Add(txtPhone);
            groupBox1.Controls.Add(label6);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(txtQuocGia);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(txtTen);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(txtHo);
            groupBox1.Location = new Point(78, 24);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(910, 517);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Thông tin khách hàng";
            // 
            // btnPrintCustomer
            // 
            btnPrintCustomer.Location = new Point(695, 137);
            btnPrintCustomer.Name = "btnPrintCustomer";
            btnPrintCustomer.Size = new Size(180, 29);
            btnPrintCustomer.TabIndex = 29;
            btnPrintCustomer.Text = "In thông tin khách hàng";
            btnPrintCustomer.UseVisualStyleBackColor = true;
            btnPrintCustomer.Click += btnPrintCustomer_Click;
            // 
            // cmbFilter
            // 
            cmbFilter.FormattingEnabled = true;
            cmbFilter.Items.AddRange(new object[] { "Họ", "Tên", "Tỉnh/TP", "Tên", "Quốc gia", "Điện thoai" });
            cmbFilter.Location = new Point(404, 177);
            cmbFilter.Name = "cmbFilter";
            cmbFilter.Size = new Size(151, 28);
            cmbFilter.TabIndex = 28;
            cmbFilter.SelectedIndexChanged += cmbFilter_SelectedIndexChanged;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(366, 182);
            label10.Name = "label10";
            label10.Size = new Size(32, 20);
            label10.TabIndex = 27;
            label10.Text = "Cột";
            // 
            // txbSearch
            // 
            txbSearch.Location = new Point(731, 179);
            txbSearch.Name = "txbSearch";
            txbSearch.Size = new Size(125, 27);
            txbSearch.TabIndex = 26;
            txbSearch.TextChanged += txbSearch_TextChanged;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(655, 185);
            label9.Name = "label9";
            label9.Size = new Size(70, 20);
            label9.TabIndex = 25;
            label9.Text = "Tìm kiếm";
            // 
            // radioGiam
            // 
            radioGiam.AutoSize = true;
            radioGiam.Location = new Point(174, 177);
            radioGiam.Name = "radioGiam";
            radioGiam.Size = new Size(93, 24);
            radioGiam.TabIndex = 24;
            radioGiam.Text = "giảm dần";
            radioGiam.UseVisualStyleBackColor = true;
            // 
            // radioTang
            // 
            radioTang.AutoSize = true;
            radioTang.Checked = true;
            radioTang.Location = new Point(77, 177);
            radioTang.Name = "radioTang";
            radioTang.Size = new Size(91, 24);
            radioTang.TabIndex = 23;
            radioTang.TabStop = true;
            radioTang.Text = "Tăng dần";
            radioTang.UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(9, 179);
            label8.Name = "label8";
            label8.Size = new Size(62, 20);
            label8.TabIndex = 22;
            label8.Text = "Sắp xếp";
            // 
            // lstTable
            // 
            lstTable.Location = new Point(9, 218);
            lstTable.Name = "lstTable";
            lstTable.Size = new Size(866, 196);
            lstTable.TabIndex = 21;
            lstTable.UseCompatibleStateImageBehavior = false;
            // 
            // lblPage
            // 
            lblPage.AutoSize = true;
            lblPage.Location = new Point(743, 420);
            lblPage.Name = "lblPage";
            lblPage.Size = new Size(0, 20);
            lblPage.TabIndex = 20;
            // 
            // btnNextPage
            // 
            btnNextPage.Location = new Point(434, 428);
            btnNextPage.Name = "btnNextPage";
            btnNextPage.Size = new Size(94, 29);
            btnNextPage.TabIndex = 18;
            btnNextPage.Text = "Trang kế";
            btnNextPage.UseVisualStyleBackColor = true;
            btnNextPage.Click += btnNextPage_Click;
            // 
            // btnBackPage
            // 
            btnBackPage.Location = new Point(304, 428);
            btnBackPage.Name = "btnBackPage";
            btnBackPage.Size = new Size(94, 29);
            btnBackPage.TabIndex = 17;
            btnBackPage.Text = "Trang trước";
            btnBackPage.UseVisualStyleBackColor = true;
            btnBackPage.Click += btnBackPage_Click;
            // 
            // cmbLine
            // 
            cmbLine.FormattingEnabled = true;
            cmbLine.Location = new Point(80, 432);
            cmbLine.Name = "cmbLine";
            cmbLine.Size = new Size(69, 28);
            cmbLine.TabIndex = 16;
            cmbLine.SelectedIndexChanged += cmbLine_SelectedIndexChanged;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(9, 432);
            label7.Name = "label7";
            label7.Size = new Size(65, 20);
            label7.TabIndex = 15;
            label7.Text = "Số dòng";
            // 
            // cmbTinhTp
            // 
            cmbTinhTp.FormattingEnabled = true;
            cmbTinhTp.Items.AddRange(new object[] { "Hà Nội", "Hải Phòng" });
            cmbTinhTp.Location = new Point(498, 46);
            cmbTinhTp.Name = "cmbTinhTp";
            cmbTinhTp.Size = new Size(182, 28);
            cmbTinhTp.TabIndex = 14;
            // 
            // btnCapNhat
            // 
            btnCapNhat.Location = new Point(564, 139);
            btnCapNhat.Name = "btnCapNhat";
            btnCapNhat.Size = new Size(94, 29);
            btnCapNhat.TabIndex = 12;
            btnCapNhat.Text = "Cập nhật";
            btnCapNhat.UseVisualStyleBackColor = true;
            btnCapNhat.Click += btnCapNhat_Click;
            // 
            // btnThemMoi
            // 
            btnThemMoi.Location = new Point(434, 138);
            btnThemMoi.Name = "btnThemMoi";
            btnThemMoi.Size = new Size(94, 29);
            btnThemMoi.TabIndex = 11;
            btnThemMoi.Text = "Thêm mới";
            btnThemMoi.UseVisualStyleBackColor = true;
            // 
            // txtPhone
            // 
            txtPhone.Location = new Point(93, 139);
            txtPhone.Name = "txtPhone";
            txtPhone.Size = new Size(149, 27);
            txtPhone.TabIndex = 10;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(327, 179);
            label6.Name = "label6";
            label6.Size = new Size(0, 20);
            label6.TabIndex = 9;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(9, 146);
            label5.Name = "label5";
            label5.Size = new Size(78, 20);
            label5.TabIndex = 8;
            label5.Text = "Điện thoại";
            // 
            // txtQuocGia
            // 
            txtQuocGia.Location = new Point(498, 91);
            txtQuocGia.Name = "txtQuocGia";
            txtQuocGia.Size = new Size(182, 27);
            txtQuocGia.TabIndex = 7;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(423, 91);
            label4.Name = "label4";
            label4.Size = new Size(69, 20);
            label4.TabIndex = 6;
            label4.Text = "Quốc gia";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(423, 46);
            label3.Name = "label3";
            label3.Size = new Size(59, 20);
            label3.TabIndex = 4;
            label3.Text = "Tỉnh/TP";
            // 
            // txtTen
            // 
            txtTen.Location = new Point(49, 88);
            txtTen.Name = "txtTen";
            txtTen.Size = new Size(193, 27);
            txtTen.TabIndex = 3;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(6, 88);
            label2.Name = "label2";
            label2.Size = new Size(32, 20);
            label2.TabIndex = 2;
            label2.Text = "Tên";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(9, 46);
            label1.Name = "label1";
            label1.Size = new Size(29, 20);
            label1.TabIndex = 1;
            label1.Text = "Họ";
            // 
            // txtHo
            // 
            txtHo.Location = new Point(49, 43);
            txtHo.Name = "txtHo";
            txtHo.Size = new Size(193, 27);
            txtHo.TabIndex = 0;
            // 
            // contextMenuStrip1
            // 
            contextMenuStrip1.ImageScalingSize = new Size(20, 20);
            contextMenuStrip1.Name = "contextMenuStrip1";
            contextMenuStrip1.Size = new Size(61, 4);
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1030, 553);
            Controls.Add(groupBox1);
            Margin = new Padding(2);
            Name = "MainForm";
            Text = "Main";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private Label label2;
        private Label label1;
        private TextBox txtHo;
        private Label label5;
        private TextBox txtQuocGia;
        private Label label4;
        private Label label3;
        private TextBox txtTen;
        private TextBox txtPhone;
        private Label label6;
        private Button btnCapNhat;
        private Button btnThemMoi;
        private ComboBox cmbTinhTp;
        private ComboBox cmbLine;
        private Label label7;
        private Label lblPage;
        private Button btnNextPage;
        private Button btnBackPage;
        private ListView lstTable;
        private Label label8;
        private RadioButton radioGiam;
        private RadioButton radioTang;
        private TextBox txbSearch;
        private Label label9;
        private ComboBox cmbFilter;
        private Label label10;
        private ContextMenuStrip contextMenuStrip1;
        private Button btnPrintCustomer;
    }
}
