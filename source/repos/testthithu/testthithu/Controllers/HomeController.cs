using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using testthithu.Models;
using System.Data.Entity;
using System.Text.RegularExpressions;
using System.IO;

namespace testthithu.Controllers
{
    public class HomeController : Controller
    {
        public QuanLyBanQuanAoEntities db = new QuanLyBanQuanAoEntities();
        public ActionResult Index()
        {
            var all = db.Sanpham.OrderBy(p =>p.Gia).ToList();
            var products = db.PhanLoaiSanPham.Include(sp => sp.Sanpham).ToList();
            ViewBag.AllProducts = all;
            return View(products);
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public ActionResult GetProductsByCategory(int? categoryId)
        {
            List<Sanpham> products;

            if (categoryId.HasValue)
            {
                
                products = db.Sanpham
                    .Where(s => s.PhanLoaiSanPhamID == categoryId.Value)
                    .ToList();
            }
            else
            {
                // Lấy tất cả sản phẩm khi categoryId là null (tab "All")
                products = db.Sanpham.ToList();
            }

            return PartialView("_ProductListPartial", products);
        }

        [HttpGet]
        public ActionResult Create()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Create(Sanpham sanPham, HttpPostedFileBase Anh)
        {
            if (Anh != null && Anh.ContentLength > 0)
            {
                var allowedExtension = new[] { ".jpg" };
                
                var fileExtension = Path.GetExtension(Anh.FileName).ToLower(); // Lấy phần mở rộng và chuyển về chữ thường

                if (fileExtension!=".jpg")
                {
                    ModelState.AddModelError("AnhDaiDien", "Chỉ chấp nhận file có định dạng .jpg.");
                }
            }
            else
            {
                ModelState.AddModelError("AnhDaiDien", "Vui lòng chọn ảnh đại diện.");
            }

            if (ModelState.IsValid)
            {
                // Lưu file và dữ liệu sản phẩm
                var path = Path.Combine(Server.MapPath("~/Content/images"), Path.GetFileName(Anh.FileName));
                Anh.SaveAs(path);
                sanPham.AnhDaiDien = Anh.FileName;

                db.Sanpham.Add(sanPham);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(sanPham);
        }
    }
}