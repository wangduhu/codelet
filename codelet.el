(defun wally/leetcode-save-problem-meta ()
  "save meta info of current problem to `wally-leetcode-current-problem'"
  (let ((line (buffer-substring-no-properties (line-beginning-position) (line-end-position))))
    (if (not (string-match "[^0-9]+\\(.+\\)" line))
        (error "unmatch leetcode line `%s'" line))
    (setq line (match-string-no-properties 1 line))
    (setq wally-leetcode-current-problem (s-split "  +" line))
    (message "get meta info `%s'" wally-leetcode-current-problem)))

(defun wally/leetcode-save-problem-desc ()
  "save problem descriptions"
  (interactive)
  (let ((raw-content (buffer-substring-no-properties (point-min) (point-max)))
        seqno
        title
        desc
        line
        (root "~/Project/codelet/problems")
        target
        )
    (with-temp-buffer
      (insert raw-content)
      (goto-char (point-min))
      (setq line (buffer-substring (line-beginning-position) (line-end-position)))
      (if (not (string-match "^\\([0-9]+\\)\\. \\([a-zA-Z0-9 ]+\\)$" line))
          (error "unmatched title line"))
      (setq seqno (string-to-number (match-string 1 line))
            title (s-replace " " "-" (downcase (match-string 2 line))))
      (re-search-forward "^\\(Easy\\|Medium\\|Hard\\)" nil t 1)
      (next-line 2)
      (setq desc (buffer-substring (line-beginning-position) (point-max)))
      (message "saving `%s'" title)
      (setq target (f-join root (format "%04d_%s.txt" seqno title)))
      (find-file-noselect target)
      (with-current-buffer (get-file-buffer target)
        (insert desc)
        (save-buffer)))))

(setq wally-leetcode-current-problem nil)

(defun wally/leetcode-save-current-problem ()
  "save leetcode's description to local text file and add a record to note file"
  (interactive)
  (let ((note-id "7870A778-2059-4BCA-BF7E-9BFB1390E99D"))
    (if (not wally-leetcode-current-problem)
        (wally/leetcode-save-problem-meta)
      (wally/leetcode-save-problem-desc)
      (org-id-goto note-id)
      (next-line)
      (re-search-forward "^\\*" nil t 1)
      (backward-char)
      (save-excursion
        (wally/org-add-new-subheading))
      (org-set-tags (s-split ", " (s-replace "-" "_" (nth 4 wally-leetcode-current-problem))))
      (setq wally-leetcode-current-problem nil))))

(spacemacs/set-leader-keys
  ";ls" 'wally/leetcode-save-current-problem
  )
