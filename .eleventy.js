const CleanCSS = require("clean-css");
const { minify } = require("terser");


module.exports = function (config) {
  config.addFilter("cssmin", function (code) {
    return new CleanCSS({}).minify(code).styles;
  });

  config.addFilter("sortByOrder", (obj) => {
    let vals = [...obj]
    return vals.sort((a, b) => Math.sign(a.data.order - b.data.order))
  })

  config.addPassthroughCopy("static");

  config.addNunjucksAsyncFilter("jsmin", async function (
    code,
    callback
  ) {
    try {
      const minified = await minify(code);
      callback(null, minified.code);
    } catch (err) {
      console.error("Terser error: ", err);
      // Fail gracefully.
      callback(null, code);
    }
  });

  return {
    dir: {
      input: "content",
      includes: "../_includes",
      data: "../_data",
      output: "_site"
    },
  }
}
