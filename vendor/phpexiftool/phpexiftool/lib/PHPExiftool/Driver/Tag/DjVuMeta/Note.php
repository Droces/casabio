<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\DjVuMeta;

use PHPExiftool\Driver\AbstractTag;

class Note extends AbstractTag
{

    protected $Id = 'note';

    protected $Name = 'Note';

    protected $FullName = 'DjVu::Meta';

    protected $GroupName = 'DjVu-Meta';

    protected $g0 = 'DjVu';

    protected $g1 = 'DjVu-Meta';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Note';

}
