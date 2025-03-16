using System;
using System.Linq;
using System.Reflection.Metadata;
using System.Windows.Forms;
using WinFormsCore.Models.Entities;
using Spire.Doc;


namespace WinFormsCore.Views
{
    public partial class MainForm : Form
    {
        private readonly QlshopContext _context;
        private int currentPage = 1;
        private int pageSize = 10;
        private int totalPages;

        private ContextMenuStrip contextMenu; // ContextMenuStrip cho ListView

        public MainForm(QlshopContext context)
        {
            InitializeComponent();
            _context = context;
            InitializeComboBox();
            InitializeListView();
            InitializeContextMenu(); // Khởi tạo ContextMenuStrip
            LoadCustomers();
            UpdatePageButtons();
        }

        // Khởi tạo combobox với các giá trị từ 10 đến 100
        private void InitializeComboBox()
        {
            cmbLine.Items.Clear();
            for (int i = 10; i <= 100; i += 10)
            {
                cmbLine.Items.Add(i.ToString());
            }
            cmbLine.SelectedIndex = 0;
        }

        // Khởi tạo cấu trúc các cột trong ListView
        private void InitializeListView()
        {
            lstTable.View = View.Details;
            lstTable.FullRowSelect = true;

            // Thêm các cột
            lstTable.Columns.Add("STT", 50);
            lstTable.Columns.Add("Họ", 150);
            lstTable.Columns.Add("Tên", 150);
            lstTable.Columns.Add("Tỉnh/TP", 150);
            lstTable.Columns.Add("Quốc gia", 150);
            lstTable.Columns.Add("Điện thoại", 150);
        }

        // Khởi tạo ContextMenuStrip cho ListView
        private void InitializeContextMenu()
        {
            contextMenu = new ContextMenuStrip();

            // Tạo các mục trong context menu
            var deleteItem = new ToolStripMenuItem("Xóa");
            var updateItem = new ToolStripMenuItem("Cập nhật");
            var detailItem = new ToolStripMenuItem("Xem chi tiết");
            var printItem = new ToolStripSplitButton("In thông tin khách hàng");

            // Gắn sự kiện khi người dùng chọn các mục
            deleteItem.Click += DeleteItem_Click;
            updateItem.Click += UpdateItem_Click;
            detailItem.Click += DetailItem_Click;
            printItem.Click += PrintItem_Click;

            // Thêm các mục vào context menu
            contextMenu.Items.AddRange(new ToolStripItem[] { deleteItem, updateItem, detailItem, printItem });

            // Gán context menu cho ListView
            lstTable.ContextMenuStrip = contextMenu;
        }

        //Xử lý sự kiện khi chọn "In thông tin khách hàng" trong ContextMenuStrip
        private void PrintItem_Click(object sender, EventArgs e)
        {
            ListViewItem listViewItem = lstTable.SelectedItems[0];

            string name = listViewItem.SubItems[0].Text; // Họ tên
            string province = listViewItem.SubItems[1].Text; // Tỉnh
            string phone = listViewItem.SubItems[2].Text; // Số điện thoại
            string country = listViewItem.SubItems[3].Text; // Quốc gia

            // Đường dẫn đến file .docx
            string filePath = @"C:\Users\PC\Downloads\wcoreFinish\wcore\WinFormsCore\Thongtinkhachhang.docx";

            // Khởi tạo Document và load file .docx
            Spire.Doc.Document document = new Spire.Doc.Document();
            document.LoadFromFile(filePath, Spire.Doc.FileFormat.Docx);

            //if (document.Bookmarks.ContainsKey("Name"))
            //    document.Bookmarks["Name"].Text = name;
            //if (document.Bookmarks.ContainsKey("Province"))
            //    document.Bookmarks["Province"].Text = province;
            //if (document.Bookmarks.ContainsKey("Phone"))
            //    document.Bookmarks["Phone"].Text = phone;
            //if (document.Bookmarks.ContainsKey("Country"))
            //    document.Bookmarks["Country"].Text = country;

            // Đọc nội dung file và hiển thị trong một TextBox hoặc MessageBox
            string content = document.GetText();
            MessageBox.Show(content); // Hoặc textBox1.Text = content;
        }

        // Xử lý sự kiện khi chọn "Xóa" trong ContextMenuStrip
        private void DeleteItem_Click(object sender, EventArgs e)
        {
            if (lstTable.SelectedItems.Count > 0)
            {
                var selectedItem = lstTable.SelectedItems[0];
                int customerId = int.Parse(selectedItem.SubItems[0].Text);

                var customer = _context.Customers.Find(customerId);
                if (customer != null)
                {
                    _context.Customers.Remove(customer);
                    _context.SaveChanges();
                    LoadCustomers(); // Tải lại danh sách sau khi xóa
                    MessageBox.Show("Đã xóa khách hàng thành công.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }

        // Xử lý sự kiện khi chọn "Cập nhật" trong ContextMenuStrip
        private void UpdateItem_Click(object sender, EventArgs e)
        {
            if (lstTable.SelectedItems.Count > 0)
            {
                var selectedItem = lstTable.SelectedItems[0];
                int customerId = int.Parse(selectedItem.SubItems[0].Text);

                var customer = _context.Customers.Find(customerId);
                if (customer != null)
                {
                    txtHo.Text = customer.LastName;
                    txtTen.Text = customer.FirstName;
                    cmbTinhTp.SelectedItem = customer.City;
                    txtQuocGia.Text = customer.Country;
                    txtPhone.Text = customer.Phone;

                    // Gọi nút cập nhật thông tin
                    btnCapNhat_Click(sender, e);
                }
            }
        }

        // Xử lý sự kiện khi chọn "Xem chi tiết" trong ContextMenuStrip
        private void DetailItem_Click(object sender, EventArgs e)
        {
            if (lstTable.SelectedItems.Count > 0)
            {
                var selectedItem = lstTable.SelectedItems[0];
                int customerId = int.Parse(selectedItem.SubItems[0].Text);

                var customer = _context.Customers.Find(customerId);
                if (customer != null)
                {
                    MessageBox.Show($"Chi tiết khách hàng:\nHọ: {customer.LastName}\nTên: {customer.FirstName}\nTỉnh/TP: {customer.City}\nQuốc gia: {customer.Country}\nĐiện thoại: {customer.Phone}",
                                    "Thông tin chi tiết", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }

        // Hàm tải dữ liệu khách hàng theo trang, sắp xếp và tìm kiếm
        private void LoadCustomers()
        {
            lstTable.Items.Clear();

            // Lấy tổng số khách hàng
            var totalCustomers = _context.Customers.Count();

            // Tính tổng số trang
            totalPages = (int)Math.Ceiling((double)totalCustomers / pageSize);

            // Lấy danh sách khách hàng theo trang hiện tại
            var customers = _context.Customers.AsQueryable();

            // Lọc kết quả tìm kiếm theo tiêu chí
            string searchKeyword = txbSearch.Text.Trim();
            string filterField = cmbFilter.SelectedItem?.ToString();

            if (!string.IsNullOrEmpty(searchKeyword))
            {
                switch (filterField)
                {
                    case "Họ":
                        customers = customers.Where(c => c.LastName.Contains(searchKeyword));
                        break;
                    case "Tên":
                        customers = customers.Where(c => c.FirstName.Contains(searchKeyword));
                        break;
                    case "Tỉnh/TP":
                        customers = customers.Where(c => c.City.Contains(searchKeyword));
                        break;
                    case "Quốc gia":
                        customers = customers.Where(c => c.Country.Contains(searchKeyword));
                        break;
                    case "Điện thoại":
                        customers = customers.Where(c => c.Phone.Contains(searchKeyword));
                        break;
                    default:
                        break;
                }
            }

            // Sắp xếp dựa trên cmbFilter và radioTang, radioGiam
            string sortField = cmbFilter.SelectedItem?.ToString();
            bool isAscending = radioTang.Checked;

            switch (sortField)
            {
                case "Họ":
                    customers = isAscending ? customers.OrderBy(c => c.LastName) : customers.OrderByDescending(c => c.LastName);
                    break;
                case "Tên":
                    customers = isAscending ? customers.OrderBy(c => c.FirstName) : customers.OrderByDescending(c => c.FirstName);
                    break;
                case "Tỉnh/TP":
                    customers = isAscending ? customers.OrderBy(c => c.City) : customers.OrderByDescending(c => c.City);
                    break;
                case "Quốc gia":
                    customers = isAscending ? customers.OrderBy(c => c.Country) : customers.OrderByDescending(c => c.Country);
                    break;
                case "Điện thoại":
                    customers = isAscending ? customers.OrderBy(c => c.Phone) : customers.OrderByDescending(c => c.Phone);
                    break;
                default:
                    customers = customers.OrderBy(c => c.Id);
                    break;
            }

            // Áp dụng phân trang với Skip và Take
            var pagedCustomers = customers.Skip((currentPage - 1) * pageSize)
                                          .Take(pageSize)
                                          .ToList();

            // Thêm khách hàng vào lstTable với số thứ tự tự tăng
            int stt = (currentPage - 1) * pageSize + 1;
            foreach (var customer in pagedCustomers)
            {
                ListViewItem item = new ListViewItem(stt.ToString());
                item.SubItems.Add(customer.LastName);
                item.SubItems.Add(customer.FirstName);
                item.SubItems.Add(customer.City);
                item.SubItems.Add(customer.Country);
                item.SubItems.Add(customer.Phone);

                lstTable.Items.Add(item);
                stt++;
            }

            // Hiển thị trang hiện tại
            lblPage.Text = $"Page {currentPage}/{totalPages}";

            // Cập nhật trạng thái nút
            UpdatePageButtons();
        }

        // Hàm cập nhật trạng thái nút phân trang
        private void UpdatePageButtons()
        {
            btnBackPage.Enabled = currentPage > 1;
            btnNextPage.Enabled = currentPage < totalPages;
        }

        // Nút BackPage để quay về trang trước
        private void btnBackPage_Click(object sender, EventArgs e)
        {
            if (currentPage > 1)
            {
                currentPage--;
                LoadCustomers(); // Tải lại dữ liệu trang trước
            }
        }

        // Nút NextPage để chuyển sang trang kế tiếp
        private void btnNextPage_Click(object sender, EventArgs e)
        {
            if (currentPage < totalPages)
            {
                currentPage++;
                LoadCustomers(); // Tải lại dữ liệu trang kế tiếp
            }
        }

        // Khi chọn một số dòng trong combobox để thay đổi pageSize
        private void cmbLine_SelectedIndexChanged(object sender, EventArgs e)
        {
            pageSize = int.Parse(cmbLine.SelectedItem.ToString());
            currentPage = 1; // Reset lại trang hiện tại về 1
            LoadCustomers(); // Tải lại dữ liệu với số lượng dòng mới
        }

        // Khi chọn một mục trong ListView
        private void lstTable_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lstTable.SelectedItems.Count == 0) return;

            var selectedItem = lstTable.SelectedItems[0];
            int customerId = int.Parse(selectedItem.SubItems[0].Text);

            var customer = _context.Customers.Find(customerId);
            if (customer != null)
            {
                txtHo.Text = customer.LastName;
                txtTen.Text = customer.FirstName;
                cmbTinhTp.SelectedItem = customer.City;
                txtQuocGia.Text = customer.Country;
                txtPhone.Text = customer.Phone;
            }
        }

        // Nút cập nhật thông tin khách hàng
        private void btnCapNhat_Click(object sender, EventArgs e)
        {
            if (lstTable.SelectedItems.Count == 0)
            {
                MessageBox.Show("Vui lòng chọn một khách hàng để cập nhật.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            var selectedItem = lstTable.SelectedItems[0];
            int customerId = int.Parse(selectedItem.SubItems[0].Text);

            var customer = _context.Customers.Find(customerId);
            if (customer != null)
            {
                customer.LastName = txtHo.Text;
                customer.FirstName = txtTen.Text;
                customer.City = cmbTinhTp.SelectedItem.ToString();
                customer.Country = txtQuocGia.Text;
                customer.Phone = txtPhone.Text;

                _context.SaveChanges();
                LoadCustomers();

                MessageBox.Show("Cập nhật thông tin khách hàng thành công.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Không tìm thấy khách hàng để cập nhật.", "Thông báo", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        // Sự kiện khi thay đổi giá trị của radioTang
        private void radioTang_CheckedChanged(object sender, EventArgs e)
        {
            LoadCustomers();
        }

        // Sự kiện khi thay đổi giá trị của radioGiam
        private void radioGiam_CheckedChanged(object sender, EventArgs e)
        {
            LoadCustomers();
        }

        // Sự kiện khi thay đổi giá trị của cmbFilter
        private void cmbFilter_SelectedIndexChanged(object sender, EventArgs e)
        {
            LoadCustomers();
        }

        // Sự kiện khi thay đổi nội dung trong ô tìm kiếm
        private void txbSearch_TextChanged(object sender, EventArgs e)
        {
            // Khi nội dung trong txtSearch thay đổi, tải lại dữ liệu khách hàng
            LoadCustomers();
        }

        private void btnPrintCustomer_Click(object sender, EventArgs e)
        {
            
        }
    }
}

