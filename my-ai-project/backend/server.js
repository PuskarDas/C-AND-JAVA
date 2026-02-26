require('dotenv').config();
const express = require('express');
const cors = require('cors');

const app = express();
app.use(cors());
app.use(express.json());

// mount verify route (ensure file exists at ./routes/verify.js)
const verifyRouter = require('./routes/verify');
app.use('/api/verify', verifyRouter);

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));