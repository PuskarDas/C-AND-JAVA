const postsData = [
    {
        username: "sky_high",
        pfp: "https://i.pravatar.cc/150?u=9",
        image: "https://images.unsplash.com/photo-1464822759023-fed622ff2c3b?auto=format&fit=crop&w=800&q=80",
        likes: 1240,
        caption: "Nothing beats this view! 🏔️",
        time: "2 HOURS AGO"
    },
    {
        username: "coder_life",
        pfp: "https://i.pravatar.cc/150?u=12",
        image: "https://images.unsplash.com/photo-1498050108023-c5249f4df085?auto=format&fit=crop&w=800&q=80",
        likes: 850,
        caption: "Night sessions are the most productive. 💻",
        time: "5 HOURS AGO"
    }
];

function renderPosts() {
    const container = document.getElementById('post-container');
    
    postsData.forEach((post, index) => {
        const postHTML = `
            <div class="post">
                <div class="post-header">
                    <div style="display:flex; align-items:center;">
                        <img src="${post.pfp}">
                        <strong>${post.username}</strong>
                    </div>
                    <i class="fas fa-ellipsis-h"></i>
                </div>
                <img src="${post.image}" class="post-img" ondblclick="toggleLike(${index})">
                <div class="post-footer">
                    <div class="action-icons">
                        <i class="far fa-heart" id="like-icon-${index}" onclick="toggleLike(${index})"></i>
                        <i class="far fa-comment"></i>
                        <i class="far fa-paper-plane"></i>
                    </div>
                    <strong><span id="likes-${index}">${post.likes}</span> likes</strong>
                    <p><strong>${post.username}</strong> ${post.caption}</p>
                    <p style="color:#8e8e8e; font-size:10px; margin-top:8px;">${post.time}</p>
                </div>
            </div>
        `;
        container.innerHTML += postHTML;
    });
}

function toggleLike(index) {
    const icon = document.getElementById(`like-icon-${index}`);
    const likesCount = document.getElementById(`likes-${index}`);
    
    if (icon.classList.contains('far')) {
        icon.classList.remove('far', 'fa-heart');
        icon.classList.add('fas', 'fa-heart', 'liked');
        postsData[index].likes += 1;
    } else {
        icon.classList.remove('fas', 'fa-heart', 'liked');
        icon.classList.add('far', 'fa-heart');
        postsData[index].likes -= 1;
    }
    likesCount.innerText = postsData[index].likes;
}

window.onload = renderPosts;