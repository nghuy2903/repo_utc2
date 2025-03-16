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
            lbltitle = new Label();
            groupBox1 = new GroupBox();
            button2 = new Button();
            button1 = new Button();
            label5 = new Label();
            label4 = new Label();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            lvLoadData = new ListView();
            label6 = new Label();
            button3 = new Button();
            label7 = new Label();
            btnPreviousPage = new Button();
            btnNextPage = new Button();
            label8 = new Label();
            button7 = new Button();
            label9 = new Label();
            button8 = new Button();
            label10 = new Label();
            button9 = new Button();
            cbbloadNumRow = new ComboBox();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // lbltitle
            // 
            lbltitle.Font = new Font("Segoe UI", 10.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lbltitle.Location = new Point(177, 26);
            lbltitle.Name = "lbltitle";
            lbltitle.Size = new Size(248, 25);
            lbltitle.TabIndex = 1;
            lbltitle.Text = "Quản lý khách hàng";
            lbltitle.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(button2);
            groupBox1.Controls.Add(button1);
            groupBox1.Controls.Add(label5);
            groupBox1.Controls.Add(label4);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Location = new Point(48, 64);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(524, 139);
            groupBox1.TabIndex = 2;
            groupBox1.TabStop = false;
            groupBox1.Text = "Thông tin khách hàng";
            // 
            // button2
            // 
            button2.Location = new Point(411, 96);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 6;
            button2.Text = "Cập nhập";
            button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            button1.Location = new Point(300, 96);
            button1.Name = "button1";
            button1.Size = new Size(94, 29);
            button1.TabIndex = 5;
            button1.Text = "Thêm mới";
            button1.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(22, 105);
            label5.Name = "label5";
            label5.Size = new Size(78, 20);
            label5.TabIndex = 4;
            label5.Text = "Điện thoại";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(273, 71);
            label4.Name = "label4";
            label4.Size = new Size(69, 20);
            label4.TabIndex = 3;
            label4.Text = "Quốc gia";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(273, 38);
            label3.Name = "label3";
            label3.Size = new Size(59, 20);
            label3.TabIndex = 2;
            label3.Text = "Tỉnh/TP";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(22, 71);
            label2.Name = "label2";
            label2.Size = new Size(32, 20);
            label2.TabIndex = 1;
            label2.Text = "Tên";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(22, 38);
            label1.Name = "label1";
            label1.Size = new Size(29, 20);
            label1.TabIndex = 0;
            label1.Text = "Họ";
            // 
            // lvLoadData
            // 
            lvLoadData.Location = new Point(48, 251);
            lvLoadData.Name = "lvLoadData";
            lvLoadData.Size = new Size(524, 121);
            lvLoadData.TabIndex = 3;
            lvLoadData.UseCompatibleStateImageBehavior = false;
            lvLoadData.SelectedIndexChanged += lvLoadData_SelectedIndexChanged;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(361, 218);
            label6.Name = "label6";
            label6.Size = new Size(70, 20);
            label6.TabIndex = 4;
            label6.Text = "Tìm kiếm";
            // 
            // button3
            // 
            button3.Location = new Point(437, 214);
            button3.Name = "button3";
            button3.Size = new Size(135, 29);
            button3.TabIndex = 5;
            button3.Text = "...";
            button3.UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(45, 393);
            label7.Name = "label7";
            label7.Size = new Size(65, 20);
            label7.TabIndex = 6;
            label7.Text = "Số dòng";
            // 
            // btnPreviousPage
            // 
            btnPreviousPage.Location = new Point(219, 388);
            btnPreviousPage.Name = "btnPreviousPage";
            btnPreviousPage.Size = new Size(94, 29);
            btnPreviousPage.TabIndex = 8;
            btnPreviousPage.Text = "Trang trước";
            btnPreviousPage.UseVisualStyleBackColor = true;
            btnPreviousPage.Click += btnPreviousPage_Click;
            // 
            // btnNextPage
            // 
            btnNextPage.Location = new Point(319, 389);
            btnNextPage.Name = "btnNextPage";
            btnNextPage.Size = new Size(94, 29);
            btnNextPage.TabIndex = 9;
            btnNextPage.Text = "Trang kế";
            btnNextPage.UseVisualStyleBackColor = true;
            btnNextPage.Click += btnNextPage_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(437, 393);
            label8.Name = "label8";
            label8.Size = new Size(46, 20);
            label8.TabIndex = 10;
            label8.Text = "Trang";
            // 
            // button7
            // 
            button7.Location = new Point(478, 388);
            button7.Name = "button7";
            button7.Size = new Size(94, 29);
            button7.TabIndex = 11;
            button7.Text = "...";
            button7.UseVisualStyleBackColor = true;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(48, 218);
            label9.Name = "label9";
            label9.Size = new Size(62, 20);
            label9.TabIndex = 12;
            label9.Text = "Sắp xếp";
            // 
            // button8
            // 
            button8.Location = new Point(106, 214);
            button8.Name = "button8";
            button8.Size = new Size(94, 29);
            button8.TabIndex = 13;
            button8.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(219, 218);
            label10.Name = "label10";
            label10.Size = new Size(32, 20);
            label10.TabIndex = 14;
            label10.Text = "Cột";
            // 
            // button9
            // 
            button9.Location = new Point(261, 214);
            button9.Name = "button9";
            button9.Size = new Size(94, 29);
            button9.TabIndex = 15;
            button9.UseVisualStyleBackColor = true;
            // 
            // cbbloadNumRow
            // 
            cbbloadNumRow.FormattingEnabled = true;
            cbbloadNumRow.Location = new Point(116, 389);
            cbbloadNumRow.Name = "cbbloadNumRow";
            cbbloadNumRow.Size = new Size(81, 28);
            cbbloadNumRow.TabIndex = 16;
            cbbloadNumRow.SelectedIndexChanged += cbbloadNumRow_SelectedIndexChanged;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(625, 514);
            Controls.Add(cbbloadNumRow);
            Controls.Add(button9);
            Controls.Add(label10);
            Controls.Add(button8);
            Controls.Add(label9);
            Controls.Add(button7);
            Controls.Add(label8);
            Controls.Add(btnNextPage);
            Controls.Add(btnPreviousPage);
            Controls.Add(label7);
            Controls.Add(button3);
            Controls.Add(label6);
            Controls.Add(lvLoadData);
            Controls.Add(groupBox1);
            Controls.Add(lbltitle);
            Margin = new Padding(2);
            Name = "MainForm";
            Text = "Main";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label lbltitle;
        private GroupBox groupBox1;
        private Button button2;
        private Button button1;
        private Label label5;
        private Label label4;
        private Label label3;
        private Label label2;
        private Label label1;
        private ListView lvLoadData;
        private Label label6;
        private Button button3;
        private Label label7;
        private Button btnPreviousPage;
        private Button btnNextPage;
        private Label label8;
        private Button button7;
        private Label label9;
        private Button button8;
        private Label label10;
        private Button button9;
        private ComboBox cbbloadNumRow;
    }
}
