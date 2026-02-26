const products = [
    { id: 1, brand: "Nike", name: "Air Jordan 1 Retro", price: 12000, img: "https://images.unsplash.com/photo-1584735175315-9d5df23860e6?q=80&w=400" },
    { id: 2, brand: "Adidas", name: "Ultraboost Light", price: 1800, img: "https://images.unsplash.com/photo-1587563871167-1ee9c731aefb?q=80&w=400" },
    { id: 3, brand: "Puma", name: "RS-X Efekt", price: 4500, img: "https://images.unsplash.com/photo-1608231387042-66d1773070a5?q=80&w=400" },
    { id: 4, brand: "Nike", name: "Revolution 6 Next", price: 3200, img: "https://images.unsplash.com/photo-1542291026-7eec264c27ff?q=80&w=400" },
    { id: 5, brand: "Adidas", name: "Stan Smith Classic", price: 1500, img: "https://images.unsplash.com/photo-1595950653106-6c9ebd614d3a?q=80&w=400" },
    { id: 6, brand: "Puma", name: "Smashic Unisex", price: 2100, img: "https://images.unsplash.com/photo-1605348532760-6753d2c43329?q=80&w=400" }
];

const productGrid = document.getElementById('productGrid');
const searchInput = document.getElementById('searchInput');

function displayProducts(filteredList) {
    productGrid.innerHTML = "";
    filteredList.forEach(product => {
        const card = `
            <div class="product-card">
                <img src="${product.img}" alt="${product.name}">
                <div class="brand-name">${product.brand}</div>
                <div class="shoe-name">${product.name}</div>
                <div class="price">₹${product.price.toLocaleString()} 
                    <img src="https://static-assets-web.flixcart.com/batman-returns/static/content/img/fa_62673a.png" class="f-assured">
                </div>
            </div>
        `;
        productGrid.innerHTML += card;
    });
}

// Search Logic
searchInput.addEventListener('input', (e) => {
    const term = e.target.value.toLowerCase();
    const filtered = products.filter(p => 
        p.name.toLowerCase().includes(term) || p.brand.toLowerCase().includes(term)
    );
    displayProducts(filtered);
});

// Initial Load
displayProducts(products);