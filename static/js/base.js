
const hamburger = document.getElementById('hamburger')
const navMenu = document.querySelector('header>nav')

if (!hamburger || !navMenu) {
  throw new Error('Missing hamburger button or navigation menu.')
}

document.getElementById('hamburger')?.addEventListener('click', toggleMobileNav);

function toggleMobileNav() {
  hamburger.classList.toggle('active')
  navMenu.classList.toggle('active')
}