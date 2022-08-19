using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using Pizzatorium.Models;

namespace Pizzatorium.Controllers
{
    [Authorize]
    public class DesignsController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Designs
        public ActionResult Index()
        {
            return View(db.Designs.ToList());
        }

        // GET: Designs/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Design design = db.Designs.Find(id);
            if (design == null)
            {
                return HttpNotFound();
            }
            return View(design);
        }

        // GET: Designs/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Designs/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create( Design design)
        {
            string _size = design.size.ToString();
            string _area = design.area.ToString();
            string _deliveryPersonnel;
            string _payment = design.payment.ToString();
            bool _complete = false;
            string _ingredient = design.ingredient.ToString();
            int ingredientCost;
           

            if(_ingredient == "Cheese")
            {
                ingredientCost = 2;
            }
            else if (_ingredient == "Capers")
            {
                ingredientCost = 3;
            }
            else if (_ingredient == "Banana")
            {
                ingredientCost = 2;
            }
            else if (_ingredient == "Avocado")
            {
                ingredientCost = 4;
            }
            else if (_ingredient == "Chicken")
            {
                ingredientCost = 5;
            }
            else if (_ingredient == "Anchovies")
            {
                ingredientCost = 5;
            }
            else if (_ingredient == "Sausage")
            {
                ingredientCost = 5;
            }
            else 
            {
                ingredientCost = 6;
            }
            

            int sizeCost = 0;
            if (_size == "Small")
            {
                sizeCost = 15;
            }
            else if (_size == "Medium")
            {
                sizeCost = 25;
            }
            else
            {
                sizeCost = 40;
            }

           if(_area == "Hatfield")
            {
                _deliveryPersonnel = "Tervin";
            }
           else if (_area == "Athlone")
            {
                _deliveryPersonnel = "James";
            }
           else if (_area == "Pretoria_North")
            {
                _deliveryPersonnel = "Leonardo";
            }
           else if (_area == "Germiston")
            {
                _deliveryPersonnel = "Craig";
            }
           else
            {
                _deliveryPersonnel = "Dwayne";
            }
         

            decimal cost = ingredientCost + sizeCost;
            if (ModelState.IsValid)
            {
                db.Designs.Add(new Design() {
                    payment = design.payment,
                    deliveryPersonnel = _deliveryPersonnel,
                    area = design.area,
                    size = design.size,
                    complete = _complete,
                    ingredient = design.ingredient,
                    cost = ingredientCost + sizeCost
                });
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(design);
        }

        // GET: Designs/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Design design = db.Designs.Find(id);
            if (design == null)
            {
                return HttpNotFound();
            }
            return View(design);
        }

        // POST: Designs/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,ingredient,size,cost,complete")] Design design)
        {
            if (ModelState.IsValid)
            {
                db.Entry(design).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(design);
        }

        // GET: Designs/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Design design = db.Designs.Find(id);
            if (design == null)
            {
                return HttpNotFound();
            }
            return View(design);
        }

        // POST: Designs/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Design design = db.Designs.Find(id);
            db.Designs.Remove(design);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ActionResult Final (int? id)
        {
            Design design = new Design();
            design = db.Designs.Find(id);
            design.complete = true;
            db.Entry(design).State = EntityState.Modified;
            db.SaveChanges();
            return View();
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
