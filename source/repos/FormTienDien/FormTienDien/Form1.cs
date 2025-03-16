using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace FormTienDien
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            InitializeListView();
            //errorProvider = new ErrorProvider();
            //errorProvider.BlinkStyle = ErrorBlinkStyle.NeverBlink; // 
        }

        private void txtNumskWh_TextChanged(object sender, EventArgs e)
        {

        }

        public class ElectricityRate
        {
            public string Level { get; set; }
            public int Price { get; set; }
            public int? MaxUsage { get; set; }

            public ElectricityRate(string level, int price, int? maxUsage)
            {
                Level = level;
                Price = price;
                MaxUsage = maxUsage;
            }
        }

        private void InitializeListView()
        {
            // Đặt các cột cho ListView
            lstItem.Columns.Add("Bậc", 100);
            lstItem.Columns.Add("Giá", 100);
            lstItem.Columns.Add("Sản lượng", 100);
            lstItem.Columns.Add("Thành tiền", 150);
            // Dữ liệu mẫu cho các bậc giá điện
            string[,] electricityRates = {
                { "Bậc 1", "1893", "50" },     // Bậc 1: 50 kWh đầu tiên
                { "Bậc 2", "1956", "50" },     // Bậc 2: từ 51 - 100 kWh
                { "Bậc 3", "2271", "100" },    // Bậc 3: từ 101 - 200 kWh
                { "Bậc 4", "2860", "100" },    // Bậc 4: từ 201 - 300 kWh
                { "Bậc 5", "3197", "100" },    // Bậc 5: từ 301 - 400 kWh
                { "Bậc 6", "3302", "∞" }       // Bậc 6: từ 401 kWh trở lên
            };

            // Thêm dữ liệu vào ListView và tính toán "Thành tiền"
            for (int i = 0; i < electricityRates.GetLength(0); i++)
            {
                ListViewItem item = new ListViewItem(electricityRates[i, 0]);
                item.SubItems.Add(electricityRates[i, 1]);  // Giá
                item.SubItems.Add(electricityRates[i, 2]);  // Sản lượng

                // Tính "Thành tiền" nếu sản lượng là một số cụ thể
                if (electricityRates[i, 2] != "∞")
                {
                    int volume = int.Parse(electricityRates[i, 2]);
                    double rate = double.Parse(electricityRates[i, 1]);
                    double total = volume * rate;

                    item.SubItems.Add(total.ToString("N0"));  // Thành tiền
                }
                else
                {
                    item.SubItems.Add("N/A");  // Không áp dụng cho bậc 6
                }

                lstItem.Items.Add(item);
            }

            // Tự động điều chỉnh kích thước các cột
            lstItem.AutoResizeColumns(ColumnHeaderAutoResizeStyle.ColumnContent);
            lstItem.AutoResizeColumns(ColumnHeaderAutoResizeStyle.HeaderSize);
        }

        private void btnCount_Click(object sender, EventArgs e)
        {

            // Lấy số điện từ TextBox
            if (!int.TryParse(txtNumskWh.Text, out int usage) || usage <= 0)
            {
                MessageBox.Show("Vui lòng nhập số điện hợp lệ lớn hơn 0.");
                return;
            }

            // Khai báo danh sách các bậc điện và giá tương ứng
            var tiers = new[]
            {
        new { Tier = "Bậc 1", Limit = 50, Price = 1893 },
        new { Tier = "Bậc 2", Limit = 100, Price = 1956 },
        new { Tier = "Bậc 3", Limit = 200, Price = 2271 },
        new { Tier = "Bậc 4", Limit = 300, Price = 2860 },
        new { Tier = "Bậc 5", Limit = 400, Price = 3197 },
        new { Tier = "Bậc 6", Limit = int.MaxValue, Price = 3302 }
    };

            // Xóa dữ liệu cũ trong ListView
            lstItem.Items.Clear();

            int remainingUsage = usage;
            decimal totalAmount = 0;

            // Duyệt qua các bậc và tính toán tiền điện theo từng bậc
            for (int i = 0; i < tiers.Length && remainingUsage > 0; i++)
            {
                var tier = tiers[i];

                // Xác định giới hạn sản lượng cho bậc hiện tại
                int previousLimit = i == 0 ? 0 : tiers[i - 1].Limit;
                int currentLimit = tier.Limit - previousLimit;

                // Tính sản lượng điện cho bậc hiện tại
                int currentUsage = Math.Min(remainingUsage, currentLimit);
                decimal amount = currentUsage * tier.Price;

                // Thêm dữ liệu vào ListView
                ListViewItem item = new ListViewItem(tier.Tier); // Cột "Bậc"
                item.SubItems.Add(tier.Price.ToString("N0") + " VND"); // Cột "Giá"
                item.SubItems.Add(currentUsage.ToString() + " kWh"); // Cột "Sản lượng"
                item.SubItems.Add(amount.ToString("N0") + " VND"); // Cột "Thành tiền"
                lstItem.Items.Add(item);

                // Cập nhật lại sản lượng còn lại và tổng tiền
                remainingUsage -= currentUsage;
                totalAmount += amount;
            }

            // Hiển thị tổng tiền (có thể sử dụng thêm một Label hoặc MessageBox để hiển thị)
            MessageBox.Show("Tổng tiền điện: " + totalAmount.ToString("N0") + " VND");
        }

        private void lstItem_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
};

