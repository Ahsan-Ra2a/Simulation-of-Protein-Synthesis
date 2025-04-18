# 🧬 DNA–Protein Conversion Engine

A C++ program that simulates the **central dogma of molecular biology**, translating a DNA sequence into its corresponding RNA and finally into an amino acid (protein) sequence. Built from scratch with custom logic, the project performs **biological validation, transcription, and translation** without using external libraries.

---

## 🔍 Overview

This project mimics the biological flow:
> **DNA → RNA → Protein**

- **DNA Validation:** Ensures input contains only valid nucleotides (`A, T, C, G`)
- **Start Codon Detection:** Locates the biological start signal `ATG`
- **Stop Codon Detection:** Recognizes `TAA`, `TAG`, or `TGA` to mark translation boundaries
- **Transcription:** Converts DNA to RNA (replacing `T` with `U`)
- **Translation:** Divides RNA into codons (triplets) and maps them to amino acids

---

## 🧪 Sample Flow

1. **User Input:** A DNA string (e.g., `ATGCGTTACTAG`)
2. **Validation:** Invalid characters trigger re-entry
3. **Transcription:** Converts DNA to RNA (e.g., `AUGCGUUACUAG`)
4. **Translation Output:** Amino acid sequence printed (e.g., `M R Y *`)
5. **Codon Range:** Indicates the exact index range of translated region in the DNA

---

## 🧠 Key Features

- Custom string parsing and codon detection
- No use of STL containers like `vector`
- Handles upper/lowercase and malformed input
- Implements complete codon-to-amino acid logic (based on standard genetic code)

---

## 🛠 Technologies

- **Language:** C++
- **Paradigm:** Procedural + Object-Oriented (class-based encapsulation)
- **Libraries:** `<iostream>`, `<cstring>`

---

## 💡 Example Output

```
Enter DNA Sequence: atgcgttgctag
Protein Sequence: M R C .
Codon Range: 0 - 11
```

---

## 📂 File Structure

- `main.cpp` — Full implementation (input, transcription, translation, and logic)
- No dependencies or build system required

---

## 🚀 How to Run

1. Compile the file:
   ```bash
   g++ main.cpp -o translator
   ```

2. Run the executable:
   ```bash
   ./translator
   ```

3. Input a DNA sequence when prompted.

---

## 🧬 Biological Accuracy

The program follows codon rules for:
- **Start:** `ATG` → Methionine (M)
- **Stop:** `TAA`, `TAG`, `TGA` → Terminator codon (`.`)

Amino acids are denoted by their **single-letter codes**.

---

## 📈 Future Enhancements

- Add GUI interface for biologists
- Support FASTA file input
- Amino acid name (full form) display
- Multi-sequence batch processing
