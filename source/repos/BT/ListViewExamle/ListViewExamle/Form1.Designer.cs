namespace ListViewExamle
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnAdd = new System.Windows.Forms.Button();
            this.txtMaSP1 = new System.Windows.Forms.TextBox();
            this.txtGiaSP1 = new System.Windows.Forms.TextBox();
            this.txtTenSP1 = new System.Windows.Forms.TextBox();
            this.txtMaSP = new System.Windows.Forms.Label();
            this.txtGiaSP = new System.Windows.Forms.Label();
            this.txtTenSP = new System.Windows.Forms.Label();
            this.lvSanPham = new System.Windows.Forms.ListView();
            this.SuspendLayout();
            // 
            // btnAdd
            // 
            this.btnAdd.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.btnAdd.Location = new System.Drawing.Point(606, 35);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(75, 37);
            this.btnAdd.TabIndex = 1;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = false;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // txtMaSP1
            // 
            this.txtMaSP1.Location = new System.Drawing.Point(171, 49);
            this.txtMaSP1.Name = "txtMaSP1";
            this.txtMaSP1.Size = new System.Drawing.Size(347, 22);
            this.txtMaSP1.TabIndex = 2;
            this.txtMaSP1.TextChanged += new System.EventHandler(this.txtMaSP_TextChanged);
            // 
            // txtGiaSP1
            // 
            this.txtGiaSP1.Location = new System.Drawing.Point(171, 178);
            this.txtGiaSP1.Name = "txtGiaSP1";
            this.txtGiaSP1.Size = new System.Drawing.Size(347, 22);
            this.txtGiaSP1.TabIndex = 3;
            this.txtGiaSP1.TextChanged += new System.EventHandler(this.txtGiaSp_TextChanged);
            // 
            // txtTenSP1
            // 
            this.txtTenSP1.Location = new System.Drawing.Point(171, 106);
            this.txtTenSP1.Name = "txtTenSP1";
            this.txtTenSP1.Size = new System.Drawing.Size(347, 22);
            this.txtTenSP1.TabIndex = 4;
            this.txtTenSP1.TextChanged += new System.EventHandler(this.txtTenSp_TextChanged);
            // 
            // txtMaSP
            // 
            this.txtMaSP.Location = new System.Drawing.Point(47, 49);
            this.txtMaSP.Name = "txtMaSP";
            this.txtMaSP.Size = new System.Drawing.Size(100, 23);
            this.txtMaSP.TabIndex = 5;
            this.txtMaSP.Text = "Mã SP";
            // 
            // txtGiaSP
            // 
            this.txtGiaSP.Location = new System.Drawing.Point(47, 181);
            this.txtGiaSP.Name = "txtGiaSP";
            this.txtGiaSP.Size = new System.Drawing.Size(100, 23);
            this.txtGiaSP.TabIndex = 6;
            this.txtGiaSP.Text = "Giá SP";
            // 
            // txtTenSP
            // 
            this.txtTenSP.Location = new System.Drawing.Point(47, 105);
            this.txtTenSP.Name = "txtTenSP";
            this.txtTenSP.Size = new System.Drawing.Size(100, 23);
            this.txtTenSP.TabIndex = 7;
            this.txtTenSP.Text = "Tên SP";
            this.txtTenSP.Click += new System.EventHandler(this.txtTenSP_Click);
            // 
            // lvSanPham
            // 
            this.lvSanPham.HideSelection = false;
            this.lvSanPham.Location = new System.Drawing.Point(39, 233);
            this.lvSanPham.Name = "lvSanPham";
            this.lvSanPham.Size = new System.Drawing.Size(711, 205);
            this.lvSanPham.TabIndex = 8;
            this.lvSanPham.UseCompatibleStateImageBehavior = false;
            this.lvSanPham.View = System.Windows.Forms.View.Details;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lvSanPham);
            this.Controls.Add(this.txtTenSP);
            this.Controls.Add(this.txtGiaSP);
            this.Controls.Add(this.txtMaSP);
            this.Controls.Add(this.txtTenSP1);
            this.Controls.Add(this.txtGiaSP1);
            this.Controls.Add(this.txtMaSP1);
            this.Controls.Add(this.btnAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.TextBox txtMaSP1;
        private System.Windows.Forms.TextBox txtGiaSP1;
        private System.Windows.Forms.TextBox txtTenSP1;
        private System.Windows.Forms.Label txtMaSP;
        private System.Windows.Forms.Label txtGiaSP;
        private System.Windows.Forms.Label txtTenSP;
        private System.Windows.Forms.ListView lvSanPham;
    }
}

