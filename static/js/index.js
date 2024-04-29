const typewriterTarget = document.getElementById('typewriter');
const typewriter = new Typewriter(typewriterTarget, {
  delay: 30,
  cursor: "█"
});

typewriter.typeString('Campamento Invernal de Programación Competitiva en Chile').start()