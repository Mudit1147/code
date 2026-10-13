const stats = document.querySelectorAll(".stat");

const observer = new IntersectionObserver((entries) => {
    entries.forEach(entry => {

        if (entry.isIntersecting) {

            entry.target.classList.add("show");

            const counter = entry.target.querySelector(".counter");

            if (!counter.dataset.started) {

                counter.dataset.started = "true";

                animateCounter(counter);

            }

        }

    });

}, {
    threshold: 0.3
});

stats.forEach(stat => observer.observe(stat));

function animateCounter(counter) {

    const target = parseFloat(counter.dataset.target);

    const suffix = counter.dataset.suffix || "";

    let current = 0;

    const duration = 1800;

    const increment = target / (duration / 20);

    const timer = setInterval(() => {

        current += increment;

        if (current >= target) {

            current = target;

            clearInterval(timer);

        }

        if (target % 1 !== 0) {

            counter.innerText = current.toFixed(2) + suffix;

        } else {

            counter.innerText = Math.floor(current).toLocaleString() + suffix;

        }

    }, 20);

}
// ================= Popup =================

const popup = document.getElementById("popup");
const closeBtn = document.querySelector(".close");

// Show popup every time page loads
window.addEventListener("load", () => {

    popup.style.display = "flex";

});

// Close popup
closeBtn.addEventListener("click", () => {

    popup.style.display = "none";

});

// Close when clicking outside
popup.addEventListener("click", (e) => {

    if (e.target === popup) {

        popup.style.display = "none";

    }

});