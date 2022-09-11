const path = require('path');
const fs = require("fs")
const {getCompiler} = require("ts-loader/dist/compilerSetup");
const outputDirPath = path.resolve(__dirname, "../../data")
const CompressionPlugin = require("compression-webpack-plugin");

module.exports = {
    entry: './src/index.tsx',
    mode: "production",
    module: {
        rules: [
            {
                test: /\.tsx?$/,
                use: 'ts-loader',
                exclude: /node_modules/,
            },
            {
                test: /\.jsx?$/,
                loader: 'babel-loader',
                exclude: /node_modules/,
            },
            {
                test: /\.css$/i,
                use: ["style-loader", "css-loader"],
            },
        ],
    },
    resolve: {
        extensions: ['.tsx', '.ts', '.js'],
    },
    output: {
        filename: 'bundle.js',
        path: outputDirPath
    },
    plugins: [
        new CompressionPlugin(),
        {
            apply: (compiler) => {
                compiler.hooks.afterEmit.tap("AfterEmitPlugin", () => {
                    const filePath = outputDirPath + "/" + "bundle.js.LICENSE.txt"
                    fs.rmSync(filePath)
                    if (fs.existsSync(filePath)){
                        console.log(outputDirPath + " removed")
                    }else{
                        console.error(outputDirPath + " not removed!")
                    }

                })
            }
        }
    ]
};