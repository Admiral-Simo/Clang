const calculateCoinTossProbabilities = (iteration: number = 100) => {
  let face: number = 0;
  let pile: number = 0;
  for (let i = 0; i < iteration; i++) {
    const randomNum = Math.round(Math.random());
    if (randomNum) {
      face++;
    } else {
      pile++;
    }
  }
  let total: number = face + pile;
  return {
    total,
    face: `${(face / total) * 100}%`,
    pile: `${(pile / total) * 100}%`,
  };
};

console.log(calculateCoinTossProbabilities());
console.log(calculateCoinTossProbabilities(1000));
console.log(calculateCoinTossProbabilities(10000));
