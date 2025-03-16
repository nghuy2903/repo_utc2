using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using ValidationMessage.Models;

namespace ValidationMessage.Controllers
{
    public class CategoryController : Controller
    {
        public static List<CategoryContext> db = new List<CategoryContext>();
        // GET: Home
        public ActionResult Index()
        {
            CategoryContext context = new CategoryContext();
            var a = context.Categories.ToList();
            return View(a);
        }
    }
}