const sort = array => {
  const { length } = array;
  if (length === 1) {
    return array;
  }

  const mid = Math.floor(length / 2);
  const left = sort(array.slice(0, mid));
  const right = sort(array.slice(mid, length));

  return merge(left, right);
};

const merge = (left, right) => {
  const notEmpty = ({ length }) => length !== 0;

  let merged = [];
  let counter = 0;

  while ([left, right].every(notEmpty)) {
    if (left[counter] >= right[counter]) {
      merged.push(left.shift());
    } else {
      merged.push(right.shift());
    }
  }

  if (left) {
    merged = merged.concat(left);
  }

  if (right) {
    merged = merged.concat(right);
  }

  return merged;
};

console.log(sort([13, 3, 45, 1, -3, 0]));
