<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Font;

use PHPExiftool\Driver\AbstractTag;

class PixHeight extends AbstractTag
{

    protected $Id = 88;

    protected $Name = 'PixHeight';

    protected $FullName = 'Font::PFM';

    protected $GroupName = 'Font';

    protected $g0 = 'Font';

    protected $g1 = 'Font';

    protected $g2 = 'Document';

    protected $Type = 'int16u';

    protected $Writable = false;

    protected $Description = 'Pix Height';

}
